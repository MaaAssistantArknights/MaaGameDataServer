package org.maa.server.gamedata.controller;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;
import lombok.extern.slf4j.Slf4j;
import org.maa.server.gamedata.constant.RedisTemplatePrefix;
import org.maa.server.gamedata.constant.ResponseCode;
import org.maa.server.gamedata.model.ResourceRequest;
import org.maa.server.gamedata.service.spi.IGameDataService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.redis.core.StringRedisTemplate;
import org.springframework.web.bind.annotation.*;

import javax.servlet.http.HttpServletRequest;
import java.util.Objects;

@Slf4j
@RestController
@RequestMapping("/gamedata")
public class GameDataController {

    private final IGameDataService gameDataService;
    private final StringRedisTemplate redisTemplate;

    @Autowired
    public GameDataController(
            IGameDataService gameDataService,
            StringRedisTemplate redisTemplate
    ) {
        this.gameDataService = gameDataService;
        this.redisTemplate = redisTemplate;
    }

    @GetMapping("/version")
    public String getVersion() {
        return this.gameDataService.currentGameDataVersion();
    }

    @PostMapping("/")
    public Object getResource(@RequestBody String body) {
        String requestKey;
        ObjectMapper mapper = new ObjectMapper();
        ResourceRequest resourceRequest;
        try {
            resourceRequest = mapper.readValue(body, ResourceRequest.class);
            int hashCode = Objects.hash(resourceRequest);
            requestKey = "#" + Integer.toHexString(hashCode);
        } catch (JsonProcessingException exception) {
            log.error("Error when processing json", exception);
            throw ResponseCode.BAD_REQUEST.getHttpException();
        }
        if (Boolean.TRUE.equals(redisTemplate.hasKey(RedisTemplatePrefix.REQUEST_CACHE + requestKey))) {
            String responseBodyStr = redisTemplate.opsForValue().get(RedisTemplatePrefix.REQUEST_CACHE + requestKey);
            try {
                return mapper.readValue(responseBodyStr, Object.class);
            } catch (JsonProcessingException ignored) {

            }
        }
        Object responseBody = this.gameDataService.getResource(resourceRequest);
        try {
            redisTemplate.opsForValue().set(
                    RedisTemplatePrefix.REQUEST_CACHE + requestKey,
                    mapper.writeValueAsString(responseBody));
        } catch (JsonProcessingException e) {
            e.printStackTrace();
        }
        return responseBody;
    }
}
