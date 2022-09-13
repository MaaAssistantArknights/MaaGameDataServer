package org.maa.server.gamedata.controller;

import org.maa.server.gamedata.model.Setting;
import org.maa.server.gamedata.service.spi.ISettingService;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class TestController {

    private final ISettingService settingService;

    public TestController(ISettingService settingService) {
        this.settingService = settingService;
    }

    @GetMapping("/")
    public String index() {
        return "Greetings from Spring Boot!";
    }


    @GetMapping("/getById")
    public Setting index(@RequestParam Integer id) {
        return settingService.getById(id);
    }

}
