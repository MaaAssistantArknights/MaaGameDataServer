package org.maa.server.gamedata.schedule;

import lombok.extern.slf4j.Slf4j;
import org.eclipse.jgit.api.Git;
import org.eclipse.jgit.api.MergeCommand;
import org.eclipse.jgit.api.errors.GitAPIException;
import org.eclipse.jgit.internal.storage.file.FileRepository;
import org.eclipse.jgit.lib.Constants;
import org.eclipse.jgit.lib.ObjectId;
import org.eclipse.jgit.lib.Repository;
import org.maa.server.gamedata.constant.RedisTemplatePrefix;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.ApplicationContext;
import org.springframework.data.redis.core.StringRedisTemplate;
import org.springframework.scheduling.annotation.Async;
import org.springframework.scheduling.annotation.EnableAsync;
import org.springframework.scheduling.annotation.Scheduled;
import org.springframework.stereotype.Component;

import java.io.File;
import java.io.IOException;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Objects;
import java.util.Set;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

@Slf4j
@Component
@EnableAsync
public class UpdateGameDataRepoSchedule {
    private static final String repoUrl = "https://github.com/yuanyan3060/Arknights-Bot-Resource";
    private Path repoDirectory = Paths.get("/data/gamedata");
    private final Lock lock = new ReentrantLock();
    private final StringRedisTemplate redisTemplate;

    @Autowired
    public UpdateGameDataRepoSchedule(
            ApplicationContext applicationContext,
            StringRedisTemplate redisTemplate
    ) {
        this.redisTemplate = redisTemplate;
        if (Objects.equals(applicationContext.getEnvironment().getActiveProfiles()[0], "dev")) {
            this.repoDirectory = Paths.get(System.getProperty("user.dir"), "target", "gamedata");
        }
    }

    public Path getRepoDirectory() {
        return this.repoDirectory;
    }

    @Scheduled(initialDelay = 0, fixedRate = 2 * 60 * 60 * 1000)
    @Async
    public void run() {
        if (!lock.tryLock()) {
            log.warn("Another update process is running, this job will not start.");
            return;
        }
        try {
            if (!checkRepoDirectory()) {
                initRepo();
            } else {
                updateRepo();
            }
        } catch (Exception e) {
            log.error("Update game data repo failed.", e);
            e.printStackTrace();
        } finally {
            lock.unlock();
        }
    }

    private boolean checkRepoDirectory() {
        File repoFolder = new File(repoDirectory.toString());
        return repoFolder.exists() && repoFolder.isDirectory();
    }

    private void initRepo() {
        try {
            log.info("1. Cloning {} to {}...", repoUrl, repoDirectory);
            Git.cloneRepository()
                    .setURI(repoUrl)
                    .setDirectory(Paths.get(repoDirectory.toString()).toFile())
                    .setBranch("main")
                    .call();
            log.info("2. Cloning Finished");
        } catch (GitAPIException e) {
            log.error("Exception occurred while cloning repo");
            e.printStackTrace();
        }
    }

    private void updateRepo() {
        try {
            log.info("1. Reading repo from local");
            Repository localRepo = new FileRepository(repoDirectory + "/.git");
            Git git = new Git(localRepo);
            log.info("2. Fetching repo from {}", repoUrl);
            git.fetch().setRemote("origin").call();
            ObjectId headId = git.getRepository().resolve(Constants.HEAD);
            ObjectId originId = git.getRepository().resolve("origin/main");
            log.info("3. Checking repo's HEAD pointer");
            // remote origin HEAD和本地HEAD不一致，触发更新
            if (!Objects.equals(headId.toString(), originId.toString())) {
                log.info("4. Updating repo to origin/main");
                git.merge().include("main", originId)
                        .setFastForward(MergeCommand.FastForwardMode.FF_ONLY)
                        .call();
                git.checkout().setName("main").call();
                this.clearRequestCache();
            } else {
                log.info("4. Everything is up-to-date");
            }
            log.info("5. Updating finished");
        } catch (IOException e) {
            log.error("Exception occurred while reading repo");
            e.printStackTrace();
        } catch (GitAPIException e) {
            log.error("Exception occurred while updating repo");
            e.printStackTrace();
        }
    }

    private void clearRequestCache() {
        Set<String> keys = redisTemplate.keys(RedisTemplatePrefix.REQUEST_CACHE + "*");
        if (keys != null) {
            redisTemplate.delete(keys);
        }
    }
}
