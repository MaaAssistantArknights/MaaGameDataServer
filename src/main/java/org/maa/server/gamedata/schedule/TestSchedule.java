package org.maa.server.gamedata.schedule;

import lombok.extern.slf4j.Slf4j;
import org.springframework.scheduling.annotation.Scheduled;
import org.springframework.stereotype.Component;

@Slf4j
@Component
public class TestSchedule {

    @Scheduled(cron = "0/5 * * * * ?")
    public void test() {
        log.info("test schedule run");
    }

}
