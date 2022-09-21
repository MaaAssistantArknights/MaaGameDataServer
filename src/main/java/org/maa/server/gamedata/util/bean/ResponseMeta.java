package org.maa.server.gamedata.util.bean;

import org.maa.server.gamedata.constant.ResponseCode;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class ResponseMeta {
    public static final ResponseMeta SUCCESS_META = new ResponseMeta(
            ResponseCode.RESULT_SUCCESS.getHttpException().getCode(),
            ResponseCode.RESULT_SUCCESS.getHttpException().getMsg()
    );

    private int code;

    private String msg;
}
