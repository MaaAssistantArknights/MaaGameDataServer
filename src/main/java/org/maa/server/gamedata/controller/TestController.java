package org.maa.server.gamedata.controller;

import org.maa.server.gamedata.model.Setting;
import org.maa.server.gamedata.service.spi.ISettingService;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
public class TestController {

    private final ISettingService settingService;

    public TestController(ISettingService settingService) {
        this.settingService = settingService;
    }

    @GetMapping("/list")
    public List<Setting> list() {
        return settingService.list();
    }


    @GetMapping("/test")
    public Setting test() {
        return new Setting("key","value");
    }
}
