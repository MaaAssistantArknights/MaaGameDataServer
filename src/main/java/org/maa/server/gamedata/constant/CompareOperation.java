package org.maa.server.gamedata.constant;

import lombok.AllArgsConstructor;
import lombok.Getter;
import org.maa.server.gamedata.util.compare.CompareOperator;
import org.maa.server.gamedata.util.compare.ICompareOperator;

@AllArgsConstructor
@Getter
public enum CompareOperation implements ICompareOperator {
    EQ(new CompareOperator("EQ", "=")),
    NEQ(new CompareOperator("NEQ", "!=")),
    GT(new CompareOperator("GT", ">")),
    GE(new CompareOperator("GE", ">=")),
    LT(new CompareOperator("LT", "<")),
    LE(new CompareOperator("LE", "<=")),
    LIKE(new CompareOperator("LIKE", "LIKE"));

    private final CompareOperator compareOperator;
}
