package org.maa.server.gamedata;

import org.mybatis.spring.annotation.MapperScan;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.scheduling.annotation.EnableScheduling;

//@MapperScan("org.maa.server.gamedata.mapper")

@EnableScheduling
@SpringBootApplication
public class MaaGameDataServerApplication {

    public static void main(String[] args) {
        SpringApplication.run(MaaGameDataServerApplication.class, args);
    }

}
