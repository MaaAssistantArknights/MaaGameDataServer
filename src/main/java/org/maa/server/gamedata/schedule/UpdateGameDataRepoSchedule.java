package org.maa.server.gamedata.schedule;

import lombok.extern.slf4j.Slf4j;
import org.eclipse.jgit.api.Git;
import org.eclipse.jgit.api.errors.GitAPIException;
import org.eclipse.jgit.internal.storage.file.FileRepository;
import org.eclipse.jgit.lib.Repository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.ApplicationContext;
import org.springframework.scheduling.annotation.Scheduled;
import org.springframework.stereotype.Component;

import java.io.File;
import java.io.IOException;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Objects;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

@Slf4j
@Component
public class UpdateGameDataRepoSchedule {
    private static final String repoUrl = "https://github.com/yuanyan3060/Arknights-Bot-Resource";
    private Path repoDirectory = Paths.get("/data/gamedata");

    private final Lock lock = new ReentrantLock();

    @Autowired
    public UpdateGameDataRepoSchedule(
            ApplicationContext applicationContext
    ) {
        if (Objects.equals(applicationContext.getEnvironment().getActiveProfiles()[0], "dev")) {
            this.repoDirectory = Paths.get(System.getProperty("user.home"), "gamedata");
        }
    }

    @Scheduled(cron = "0 0 0/2 * * *")
    public void runSchedule() {
        if (!lock.tryLock()) {
            log.info("Another update process is running, this job will not start.");
            return;
        }
        try {
            if (!checkRepoDirectory()) {
                initRepo();
            } else {
                updateRepo();
            }
        }
        catch (Exception e) {
            log.error("Update game data repo failed.", e);
            e.printStackTrace();
        }
        finally {
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
            log.info("2. Pulling repo from {}", repoUrl);
            git.pull().call();
            log.info("3. Pulling Finished");
        } catch (IOException e) {
            log.error("Exception occurred while reading repo");
            e.printStackTrace();
        } catch (GitAPIException e) {
            log.error("Exception occurred while pulling repo");
            e.printStackTrace();
        }
    }
}
