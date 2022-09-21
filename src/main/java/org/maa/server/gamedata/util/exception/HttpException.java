package org.maa.server.gamedata.util.exception;

import lombok.AllArgsConstructor;
import lombok.Getter;
import org.springframework.http.HttpStatus;

@AllArgsConstructor
@Getter
public class HttpException extends RuntimeException {
    private int code;
    protected HttpStatus httpStatus;
    private String msg;

    public HttpException(int code) {
        this.code = code;
    }

    public static class HttpExceptionBuilder {
        private int code;
        private HttpStatus httpStatus;
        private String msg;

        public HttpExceptionBuilder() {

        }

        public HttpExceptionBuilder(HttpException httpException) {
            this.code = httpException.getCode();
            this.httpStatus = httpException.getHttpStatus();
            this.msg = httpException.getMsg();
        }

        public HttpExceptionBuilder msg(String msg) {
            this.msg = msg;
            return this;
        }

        public HttpExceptionBuilder code(int code) {
            this.code = code;
            return this;
        }

        public HttpExceptionBuilder httpStatus(HttpStatus httpStatus) {
            this.httpStatus = httpStatus;
            return this;
        }

        public HttpException build() {
            return new HttpException(code, httpStatus, msg);
        }
    }
}
