package org.maa.server.gamedata.service.impl;

import com.baomidou.mybatisplus.core.conditions.Wrapper;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import lombok.extern.slf4j.Slf4j;
import org.maa.server.gamedata.mapper.SettingMapper;
import org.maa.server.gamedata.model.Setting;
import org.maa.server.gamedata.service.spi.ISettingService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.Collection;
import java.util.Map;
import java.util.function.Function;

@Slf4j
@Service
public class SettingServiceImpl implements ISettingService {

    private final SettingMapper settingMapper;

    //构造器注入
    @Autowired
    public SettingServiceImpl(SettingMapper settingMapper) {
        this.settingMapper = settingMapper;
    }

    @Override
    public boolean saveBatch(Collection<Setting> entityList, int batchSize) {
        return false;
    }

    @Override
    public boolean saveOrUpdateBatch(Collection<Setting> entityList, int batchSize) {
        return false;
    }

    @Override
    public boolean updateBatchById(Collection<Setting> entityList, int batchSize) {
        return false;
    }

    @Override
    public boolean saveOrUpdate(Setting entity) {
        return false;
    }

    @Override
    public Setting getOne(Wrapper<Setting> queryWrapper, boolean throwEx) {
        return null;
    }

    @Override
    public Map<String, Object> getMap(Wrapper<Setting> queryWrapper) {
        return null;
    }

    @Override
    public <V> V getObj(Wrapper<Setting> queryWrapper, Function<? super Object, V> mapper) {
        return null;
    }

    @Override
    public BaseMapper<Setting> getBaseMapper() {
        return this.settingMapper;
    }

    @Override
    public Class<Setting> getEntityClass() {
        return Setting.class;
    }
}
