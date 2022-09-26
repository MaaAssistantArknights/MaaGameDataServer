package org.maa.server.gamedata.model;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.fasterxml.jackson.annotation.JsonIgnore;
import lombok.Data;

import java.sql.Timestamp;

@Data
public class BaseResource {

    @TableId(type = IdType.AUTO)
    private Integer id;

    @JsonIgnore
    @TableField(fill = FieldFill.INSERT)
    private Timestamp createTime;

    @JsonIgnore
    @TableField(fill = FieldFill.INSERT_UPDATE)
    private Timestamp updateTime;

}
