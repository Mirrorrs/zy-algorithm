//
// Created by ma on 18-6-29.
//

#ifndef _GREATDIVIDE_H__
#define _GREATDIVIDE_H__

#include "sqList.h"


// 大整数除以int,这个函数的除数默认是2
sqList greatDivide(sqList L);

sqList greatDivide(sqList L) {

    int temp = 0;
    sqList result;
    initList(result);
    for(int i=0; i<L.length; i++) appendList(result, 0);
    int len = L.length;
    for(int i=0; i<len; i++){
        result.elem[i] += L.elem[i] / 2;
        result.elem[i+1] = L.elem[i]%2*10 / 2;
    }
    if(result.elem[0]==0) deleteElem(result, 1);
    return result;
}

#endif //PROJECT_GREATDIVIDE_H
