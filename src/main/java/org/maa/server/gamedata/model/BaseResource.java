package org.maa.server.gamedata.model;

import com.alibaba.fastjson.annotation.JSONField;
import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import lombok.Data;

import java.sql.Timestamp;

@Data
public class BaseResource {
    @TableId(type = IdType.AUTO)
    private Integer id;

    @JSONField(deserialize = false)
    @TableField(fill = FieldFill.INSERT)
    private Timestamp createTime;

    @JSONField(deserialize = false)
    @TableField(fill = FieldFill.INSERT_UPDATE)
    private Timestamp updateTime;
}
