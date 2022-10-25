package org.maa.server.gamedata.service.spi;

public interface IGameDataService {
    String currentGameDataVersion();

    Object getResource(Object body);
}
