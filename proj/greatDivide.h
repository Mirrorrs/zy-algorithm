//
// Created by ma on 18-6-30.
//

#ifndef PROJECT_GREATDIVIDE_H
#define PROJECT_GREATDIVIDE_H

#include "sqList.h"

sqList greatDivide(sqList L){
    // 这个函数的除数默认是2
    int temp = 0;
    sqList result;
    init_list(result);
    for(int i=0; i<L.length; i++) append_list(result, 0);
    int len = L.length;
    for(int i=0; i<len; i++){
        result.elem[i] += L.elem[i] / 2;
        result.elem[i+1] = L.elem[i]%2*10 / 2;
    }
    if(result.elem[0]==0) delete_elem(result, 1);
    return result;
}

#endif //PROJECT_GREATDIVIDE_H
