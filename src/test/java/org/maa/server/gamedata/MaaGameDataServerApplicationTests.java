package org.maa.server.gamedata;

import org.junit.jupiter.api.Test;
import org.maa.server.gamedata.model.Setting;
import org.maa.server.gamedata.service.spi.ISettingService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

@SpringBootTest
class MaaGameDataServerApplicationTests {

    @Autowired
    private ISettingService settingService;

    @Test
    void contextLoads() {
        Setting setting = new Setting();
        setting.setKey("test.key");
        setting.setValue("test.value");
    }

}
