package org.maa.server.gamedata.util;

import com.baomidou.mybatisplus.core.handlers.MetaObjectHandler;
import org.apache.ibatis.reflection.MetaObject;
import org.springframework.context.annotation.Configuration;

import java.sql.Timestamp;
import java.util.Date;

@Configuration
public class BaseResourceMetaObjectHandler implements MetaObjectHandler {
    @Override
    public void insertFill(MetaObject metaObject) {
        this.setFieldValByName("createTime", new Timestamp(new Date().getTime()), metaObject);
        this.setFieldValByName("updateTime", new Timestamp(new Date().getTime()), metaObject);
    }

    @Override
    public void updateFill(MetaObject metaObject) {
        this.setFieldValByName("updateTime", new Timestamp(new Date().getTime()), metaObject);
    }
}
