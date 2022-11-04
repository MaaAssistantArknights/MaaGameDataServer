package org.maa.server.gamedata.config;

import org.maa.server.gamedata.schedule.UpdateGameDataRepoSchedule;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Configuration;
import org.springframework.web.servlet.config.annotation.ResourceHandlerRegistry;
import org.springframework.web.servlet.config.annotation.WebMvcConfigurationSupport;

import java.io.File;
import java.nio.file.Path;

@Configuration
public class StaticResourceConfig extends WebMvcConfigurationSupport {

    private final UpdateGameDataRepoSchedule updateGameDataRepoSchedule;

    @Autowired
    StaticResourceConfig(
            UpdateGameDataRepoSchedule updateGameDataRepoSchedule
    ) {
        this.updateGameDataRepoSchedule = updateGameDataRepoSchedule;
    }
    @Override
    protected void addResourceHandlers(ResourceHandlerRegistry registry) {
        Path repoDirectory = updateGameDataRepoSchedule.getRepoDirectory();
        String repoDirectoryPath = "file://" + repoDirectory.toString() + File.separator;
        registry.addResourceHandler("/raw/**").addResourceLocations(repoDirectoryPath);
        super.addResourceHandlers(registry);
    }
}
