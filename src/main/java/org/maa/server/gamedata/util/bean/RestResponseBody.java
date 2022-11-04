package org.maa.server.gamedata.util.bean;

import io.swagger.v3.oas.annotations.media.Schema;
import lombok.Data;

@Data
@Schema(description = "")
public class RestResponseBody<T> {

    public RestResponseBody(int code, String msg) {
        this.code = code;
        this.msg = msg;
    }

    public RestResponseBody(ResponseMeta meta, T data) {
        this.code = meta.getCode();
        this.msg = meta.getMsg();
        this.data = data;
    }

    private int code;

    private String msg;

    private T data;
}
