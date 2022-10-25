package org.maa.server.gamedata.controller;

import org.maa.server.gamedata.service.spi.IGameDataService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

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
    public Object getResource(@RequestBody Object body) {
        return this.gameDataService.getResource(body);
    }
}
