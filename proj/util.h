//
// Created by ma on 18-6-29.
//

#ifndef PROJECT_UTIL_H
#define PROJECT_UTIL_H

#include "sqList.h"
#include <cstring>
#include <iostream>

// 编写一个函数将字符串转为线性表
sqList ConvertCharArrayToSqList(char* s){
    sqList result;
    init_list(result);
    int len = strlen(s);
    // 正序转换, result中的顺序和s一样
    for (int i=0; i < len; i ++) append_list(result, s[i]-'0');
    return result;
}

// 编写一个函数判断int类型是否为奇数
int isUneven(int m){
    return m%2;
}

// 编写一个函数判断一个大整数是否为奇数
int greatIsUneven(sqList L){
    return L.elem[L.length-1]%2;
}

#endif //PROJECT_UTIL_H
