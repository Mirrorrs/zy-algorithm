#ifndef _GREATERMULTIPLE__
#define _GREATERMULTIPLE__

#include<iostream>
#include"sqList.h"
using namespace std;

sqList greatMultiple(sqList L, int base){
    int temp = 0;
    int len = L.length;
    sqList result;
    init_list(result);

    for(int i=len-1; i>=0; i--){
        // 如果有进位
        if(L.elem[i]>=5){


            temp = L.elem[i-1];
            temp += L.elem[i]*base%10;
            append_list(result, temp);
            result.elem[i] += L.elem[i]*base/10;
        }else{
            result.elem[i] += L.elem[i]*base;
        }
    }
    tight_print(result);
    return result;
}

#endif