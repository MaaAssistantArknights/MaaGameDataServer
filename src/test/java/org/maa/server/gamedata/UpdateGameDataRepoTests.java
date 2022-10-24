package org.maa.server.gamedata;

import org.junit.jupiter.api.Test;
import org.maa.server.gamedata.schedule.UpdateGameDataRepoSchedule;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.ActiveProfiles;

@SpringBootTest
@ActiveProfiles("dev")
class UpdateGameDataRepoTests {

    private final UpdateGameDataRepoSchedule updateGameDataRepoSchedule;

    @Autowired
    public UpdateGameDataRepoTests(UpdateGameDataRepoSchedule updateGameDataRepoSchedule) {
        this.updateGameDataRepoSchedule = updateGameDataRepoSchedule;
    }

    @Test
    void contextLoads() {
        this.updateGameDataRepoSchedule.run();
    }

}
