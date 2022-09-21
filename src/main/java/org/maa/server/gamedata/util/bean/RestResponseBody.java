package org.maa.server.gamedata.util.bean;

import io.swagger.v3.oas.annotations.media.Schema;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@AllArgsConstructor
@NoArgsConstructor
@Data
@Schema(description = "")
public class RestResponseBody<T> {

    private ResponseMeta meta;

    private T data;
}
