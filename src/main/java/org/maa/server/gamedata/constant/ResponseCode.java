package org.maa.server.gamedata.constant;

import org.maa.server.gamedata.util.exception.HttpErrorCode;
import org.maa.server.gamedata.util.exception.HttpException;
import lombok.AllArgsConstructor;
import lombok.Getter;
import org.springframework.http.HttpStatus;

@AllArgsConstructor
@Getter
public enum ResponseCode implements HttpErrorCode {
    RESULT_SUCCESS(new HttpException(0, HttpStatus.OK, "请求成功"));

    private final HttpException httpException;
}
