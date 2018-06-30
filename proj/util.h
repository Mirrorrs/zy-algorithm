//
// Created by ma on 18-6-29.
//

#ifndef _UTIL_H_
#define _UTIL_H_

#include "sqList.h"
#include <cstring>
#include <iostream>

// 编写一个函数将字符串转为线性表
sqList ConvertCharArrayToSqList(char* s);

// 编写一个函数判断一个大整数是否为奇数
int greatIsUneven(sqList L);

sqList ConvertCharArrayToSqList(char *s) {
    sqList result;
    initList(result);
    int len = strlen(s);
    // 正序转换, result中的顺序和s一样
    for (int i=0; i < len; i ++) appendList(result, s[i] - '0');
    return result;
}

int greatIsUneven(sqList L) {
    return L.elem[L.length-1]%2;
}

#endif //PROJECT_UTIL_H
