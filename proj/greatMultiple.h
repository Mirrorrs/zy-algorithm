#ifndef _GREATERMULTIPLE__
#define _GREATERMULTIPLE__

#include<iostream>
#include"sqList.h"
using namespace std;

sqList greatMultiple(sqList L, int base){
    int temp = 0;
    //在最高位前添加一个0用于解决进位问题
    insert_elem(L, 1, 0);
    int len = L.length;
    sqList convertedResult, result;
    init_list(convertedResult);
    init_list(result);

    for(int i=len-1; i>=0; i--){
        //计算当前位的结果, 加上前一位的进位结果
        append_list(convertedResult, L.elem[i]*base%10+temp);
        //计算下一位是否有进位
        temp = L.elem[i]*base/10;
    }
    //舍去结果中最高位之前的0
    if(convertedResult.elem[convertedResult.length-1]==0)
        delete_elem(convertedResult, convertedResult.length);
    //正序保存结果
    for(int i=convertedResult.length-1; i>=0; i--)
        append_list(result, convertedResult.elem[i]);
    return result;
}

#endif