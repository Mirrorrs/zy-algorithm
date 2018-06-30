//
// Created by ma on 18-6-29.
//

#ifndef _GREATERMULTIPLE__
#define _GREATERMULTIPLE__

#include "sqList.h"

// 大整数与int类型相乘.
sqList greatMultiple(sqList L, int base);

sqList greatMultiple(sqList L, int base) {
    int temp = 0;
    //在最高位前添加一个0用于解决进位问题
    insertElem(L, 1, 0);
    int len = L.length;
    sqList convertedResult, result;
    initList(convertedResult);
    initList(result);

    for(int i=len-1; i>=0; i--){
        //计算当前位的结果, 加上前一位的进位结果
        appendList(convertedResult, L.elem[i] * base % 10 + temp);
        //计算下一位是否有进位
        temp = L.elem[i]*base/10;
    }
    //舍去结果中最高位之前的0
    if(convertedResult.elem[convertedResult.length-1]==0)
        deleteElem(convertedResult, convertedResult.length);
    //正序保存结果
    for(int i=convertedResult.length-1; i>=0; i--)
        appendList(result, convertedResult.elem[i]);
    return result;
}

#endif