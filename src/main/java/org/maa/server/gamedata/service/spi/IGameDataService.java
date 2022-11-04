package org.maa.server.gamedata.service.spi;

import org.maa.server.gamedata.model.ResourceRequest;

public interface IGameDataService {
    String currentGameDataVersion();

    Object getResource(ResourceRequest body);
}
