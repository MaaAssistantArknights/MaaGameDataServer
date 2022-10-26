package org.maa.server.gamedata.util.compare;

import org.maa.server.gamedata.constant.CompareOperation;
import org.maa.server.gamedata.util.exception.HttpException;

import java.util.HashMap;
import java.util.Map;

public class CompareOperator {
    private final String operator;
    private final String operation;

    public CompareOperator(String operation, String operator) {
        this.operation = operation;
        this.operator = operator;
    }

    public static class CompareOperatorBuilder {
        private String operator;
        private String operation;

        public CompareOperatorBuilder() {

        }

        public CompareOperatorBuilder(CompareOperator compareOperator) {
            this.operator = compareOperator.operator;
            this.operation = compareOperator.operation;
        }

        public CompareOperatorBuilder operator(String operator) {
            this.operator = operator;
            return this;
        }

        public CompareOperatorBuilder operation(String operation) {
            this.operation = operation;
            return this;
        }

        public CompareOperator build() {
            return new CompareOperator(operation, operator);
        }
    }
}
