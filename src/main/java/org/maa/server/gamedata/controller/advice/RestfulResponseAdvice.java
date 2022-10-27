package org.maa.server.gamedata.controller.advice;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;
import lombok.extern.slf4j.Slf4j;
import org.maa.server.gamedata.util.bean.ResponseMeta;
import org.maa.server.gamedata.util.bean.RestResponseBody;
import org.springframework.core.MethodParameter;
import org.springframework.http.MediaType;
import org.springframework.http.converter.HttpMessageConverter;
import org.springframework.http.server.ServerHttpRequest;
import org.springframework.http.server.ServerHttpResponse;
import org.springframework.web.bind.annotation.RestControllerAdvice;
import org.springframework.web.servlet.mvc.method.annotation.ResponseBodyAdvice;

@RestControllerAdvice
@Slf4j
public class RestfulResponseAdvice implements ResponseBodyAdvice<Object> {

    private final ObjectMapper objectMapper = new ObjectMapper();

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
        if (body instanceof RestResponseBody) {
            return body;
        }
        if (body instanceof String) {
            try {
                return objectMapper.writeValueAsString(new RestResponseBody<>(ResponseMeta.SUCCESS_META, body));
            } catch (JsonProcessingException e) {
                log.error("Error when convert object to json string", e);
            }
        }
        return new RestResponseBody<>(ResponseMeta.SUCCESS_META, body);
    }

//    @ExceptionHandler(value = HttpException.class)
//    public ResponseEntity exceptionHandler(HttpException exception) {
//        return RestResponseEntity.error(exception);
//    }

}
