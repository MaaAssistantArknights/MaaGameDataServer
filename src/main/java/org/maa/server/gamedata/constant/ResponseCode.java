package org.maa.server.gamedata.constant;

import org.maa.server.gamedata.util.exception.HttpErrorCode;
import org.maa.server.gamedata.util.exception.HttpException;
import lombok.AllArgsConstructor;
import lombok.Getter;
import org.springframework.http.HttpStatus;

@AllArgsConstructor
@Getter
public enum ResponseCode implements HttpErrorCode {
    RESULT_SUCCESS(new HttpException(0, HttpStatus.OK, "请求成功")),
    BAD_REQUEST(new HttpException(400, HttpStatus.BAD_REQUEST, "请求参数不正确")),
    UNAUTHORIZED(new HttpException(401, HttpStatus.UNAUTHORIZED, "账号未登录")),
    FORBIDDEN(new HttpException(403, HttpStatus.FORBIDDEN, "没有该操作权限")),
    NOT_FOUND(new HttpException(404, HttpStatus.NOT_FOUND, "请求未找到")),
    METHOD_NOT_ALLOWED(new HttpException(405, HttpStatus.METHOD_NOT_ALLOWED, "请求方法不正确")),
    LOCKED(new HttpException(423, HttpStatus.LOCKED, "请求失败，请稍后重试")),
    TOO_MANY_REQUESTS(new HttpException(429, HttpStatus.TOO_MANY_REQUESTS, "请求过于频繁，请稍后重试")),
    INTERNAL_SERVER_ERROR(new HttpException(500, HttpStatus.INTERNAL_SERVER_ERROR, "系统异常")),
    REPEATED_REQUESTS(new HttpException(900, HttpStatus.OK, "重复请求，请稍后重试")),
    DEMO_DENY(new HttpException(901, HttpStatus.OK, "演示模式，禁止写操作")),
    UNKNOWN(new HttpException(999, HttpStatus.OK, "未知错误"));


    private final HttpException httpException;
}
