package org.maa.server.gamedata.controller.advice;

import lombok.extern.slf4j.Slf4j;
import org.maa.server.gamedata.util.bean.ResponseMeta;
import org.maa.server.gamedata.util.bean.RestResponseBody;
import org.maa.server.gamedata.util.bean.RestResponseEntity;
import org.maa.server.gamedata.util.exception.HttpException;
import org.slf4j.MDC;
import org.springframework.core.MethodParameter;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.http.converter.HttpMessageConverter;
import org.springframework.http.server.ServerHttpRequest;
import org.springframework.http.server.ServerHttpResponse;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.bind.annotation.RestControllerAdvice;
import org.springframework.web.servlet.mvc.method.annotation.ResponseBodyAdvice;

@RestControllerAdvice
@Slf4j
public class RestfulResponseAdvice implements ResponseBodyAdvice<Object> {

    @Override
    public boolean supports(MethodParameter returnType, Class<? extends HttpMessageConverter<?>> converterType) {
        if ("org.springframework.http.ResponseEntity".equals(returnType.getGenericParameterType().getTypeName())) {
            return false;
        }
        final String className = returnType.getContainingClass().getCanonicalName();
        return className.startsWith("org.maa");
    }

    @Override
    public Object beforeBodyWrite(Object body, MethodParameter returnType, MediaType selectedContentType, Class<? extends HttpMessageConverter<?>> selectedConverterType, ServerHttpRequest request, ServerHttpResponse response) {
        return new RestResponseBody<>(ResponseMeta.SUCCESS_META, body);
    }

    @ExceptionHandler(value = HttpException.class)
    public ResponseEntity exceptionHandler(HttpException exception) {
        return RestResponseEntity.error(exception);
    }

}
