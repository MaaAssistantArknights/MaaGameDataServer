package org.maa.server.gamedata.util.bean;

import org.maa.server.gamedata.util.exception.HttpErrorCode;
import org.maa.server.gamedata.util.exception.HttpException;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import reactor.util.annotation.Nullable;

public class RestResponseEntity {
    public interface RestResponseBuilder {
        RestResponseBuilder header(String headerName, String... headerValues);

        RestResponseBuilder headers(@Nullable HttpHeaders headers);

        ResponseEntity build();

        ResponseEntity body(Object body);
    }

    public static class DefaultBuilder implements RestResponseBuilder {
        private final ResponseEntity.BodyBuilder builder;
        private final ResponseMeta meta;

        public DefaultBuilder() {
            this.builder = ResponseEntity.ok();
            this.meta = ResponseMeta.SUCCESS_META;
        }

        public DefaultBuilder(HttpException e) {
            this.builder = ResponseEntity.status(e.getHttpStatus());
            this.meta = new ResponseMeta(e.getCode(), e.getMsg());
        }

        public DefaultBuilder(HttpStatus httpStatus, int code, String msg) {
            this.builder = ResponseEntity.status(httpStatus);
            this.meta = new ResponseMeta(code, msg);
        }

        @Override
        public RestResponseBuilder header(String headerName, String... headerValues) {
            builder.header(headerName, headerValues);
            return this;
        }

        @Override
        public RestResponseBuilder headers(HttpHeaders headers) {
            builder.headers(headers);
            return this;
        }

        @Override
        public ResponseEntity build() {
            return builder.body(new RestResponseBody<>(meta, null));
        }

        @Override
        public ResponseEntity body(Object body) {
            return builder.body(new RestResponseBody<>(meta, body));
        }
    }


    public static RestResponseBuilder ok() {
        return new DefaultBuilder();
    }

    public static RestResponseBuilder errorBuilder(HttpErrorCode errorCode) {
        return new DefaultBuilder(errorCode.getHttpException());
    }

    public static RestResponseBuilder errorBuilder(HttpStatus httpStatus, int code, String msg) {
        return new DefaultBuilder(httpStatus, code, msg);
    }

    public static ResponseEntity<Object> ok(Object body) {
        return ResponseEntity.ok().body(new RestResponseBody<>(ResponseMeta.SUCCESS_META, body));
    }

    public static ResponseEntity<Object> error(HttpException exception) {
        ResponseMeta meta = new ResponseMeta(exception.getCode(), exception.getMsg());
        return ResponseEntity.status(exception.getHttpStatus()).body(new RestResponseBody<>(meta, (Object)null));
    }

    public static ResponseEntity<Object> error(int code, String msg, HttpStatus httpStatus) {
        ResponseMeta meta = new ResponseMeta(code, msg);
        return ResponseEntity.status(httpStatus).body(new RestResponseBody<>(meta, (Object)null));
    }
}
