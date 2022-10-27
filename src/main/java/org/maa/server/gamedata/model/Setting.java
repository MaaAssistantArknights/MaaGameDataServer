package org.maa.server.gamedata.model;

import com.baomidou.mybatisplus.annotation.TableName;
import io.swagger.v3.oas.annotations.media.Schema;
import lombok.*;
import org.springframework.validation.annotation.Validated;

@AllArgsConstructor
@NoArgsConstructor
@EqualsAndHashCode(callSuper = true)
@Data
@Validated
@TableName(value = "gamedata.setting")
@Schema(description = "服务器设置")
@Builder
public class Setting extends BaseResource {
    @Schema(description = "设置键", example = "schedule.auto_update.interval")
    private String key;
    @Schema(description = "设置值", example = "20")
    private String value;
}
