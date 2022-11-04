package org.maa.server.gamedata.model;

import io.swagger.v3.oas.annotations.media.Schema;
import org.maa.server.gamedata.constant.CompareOperation;
import org.maa.server.gamedata.constant.ResourceType;

import java.util.List;

@Schema(description = "资源请求标准")
public class ResourceRequest {

    @Schema(description = "请求资源种类", example = "Character")
    public ResourceType.Type type;

    @Schema(description = "过滤器（他们为逻辑和的关系）")
    public List<Filter> filters;

    public static class Filter {
        @Schema(description = "过滤字段路径", example = "name")
        public String path;

        @Schema(description = "比较操作符", example = "EQ")
        public CompareOperation compareOperation;

        @Schema(description = "比较值", example = "Lancet-2")
        public String value;
    }

    @Override
    public int hashCode() {
        int result = 17;
        result = 31 * result + (type != null ? type.toString().hashCode() : 0);
        for (var filter : filters) {
            result = 31 * result + (filter.path != null ? filter.path.hashCode() : 0);
            result = 31 * result + (filter.path != null ? filter.compareOperation.toString().hashCode() : 0);
            result = 31 * result + (filter.path != null ? filter.value.hashCode() : 0);
        }
        return result;
    }
}

