package org.maa.server.gamedata.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;
import org.maa.server.gamedata.model.Setting;

@Mapper
public interface SettingMapper extends BaseMapper<Setting> {
}
