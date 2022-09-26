package org.maa.server.gamedata.mapper;

import org.apache.ibatis.annotations.Mapper;
import org.maa.server.gamedata.model.Setting;
import org.maa.server.gamedata.query.QueryWrapperX;

import java.util.List;

@Mapper
public interface SettingMapper extends BaseMapperX<Setting> {

    default List<Setting> selectByKey(String key) {
        return selectList(new QueryWrapperX<Setting>().eqIfPresent("key", key));
    }

}
