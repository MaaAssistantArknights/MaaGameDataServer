package org.maa.server.gamedata.service.impl;

import lombok.extern.slf4j.Slf4j;
import org.maa.server.gamedata.constant.ResourceType;
import org.maa.server.gamedata.constant.ResponseCode;
import org.maa.server.gamedata.model.ResourceRequest;
import org.maa.server.gamedata.schedule.UpdateGameDataRepoSchedule;
import org.maa.server.gamedata.service.spi.IGameDataService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.Objects;

@Slf4j
@Service
public class GameDataServiceImpl implements IGameDataService {

    private final UpdateGameDataRepoSchedule updateGameDataRepoSchedule;

    @Autowired
    public GameDataServiceImpl(
            UpdateGameDataRepoSchedule updateGameDataRepoSchedule
    ) {
        this.updateGameDataRepoSchedule = updateGameDataRepoSchedule;
    }

    public String currentGameDataVersion() {
        Path path = this.updateGameDataRepoSchedule.getRepoDirectory();
        try {
            return Files.readString(Paths.get(path.toString(), "version"));
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public Object getResource(ResourceRequest resourceRequest) {
        if (Arrays.stream(ResourceType.typeList).noneMatch(type -> Objects.equals(type, resourceRequest.type.toString()))) {
            throw ResponseCode.NOT_FOUND.getHttpException();
        }
        // TODO: support resource from json files
        return resourceRequest;
    }
}
