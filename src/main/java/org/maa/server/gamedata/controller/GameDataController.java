package org.maa.server.gamedata.controller;

import org.maa.server.gamedata.service.spi.IGameDataService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/gamedata")
public class GameDataController {

    private final IGameDataService gameDataService;

    @Autowired
    public GameDataController(
            IGameDataService gameDataService
    ) {
        this.gameDataService = gameDataService;
    }

    @GetMapping("/version")
    public String getVersion() {
        return this.gameDataService.currentGameDataVersion();
    }

    @PostMapping("/")
    public Object getResource() {
        return this.gameDataService.getResource();
    }
}
