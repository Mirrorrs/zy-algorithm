# ifndef __GREATERMINUS__H__
# define __GREATERMINUS__H__

#include<cstdio>
#include<cstring>
#include<iostream>
#include"sqList.h"
#define mlen 100

using namespace std;

// 编写一个函数将字符串转为线性表
sq_list convert_char_array_to_sq_list(char* s){
    sq_list result;
    init_list(result);
    int len = strlen(s);
    // 正序转换, result中的顺序和s一样
    for (int i=0; i < len; i ++) append_list(result, s[i]-'0');
    return result;
}


sq_list greaterMinus(sq_list a1, sq_list a2){
    int temp=0;
	sq_list tempA2;
	init_list(tempA2);
	cp_sq_list(a2, tempA2);
    int len1, len2;
    len1 = a1.length;
    len2 = tempA2.length;
	// 为位数不足的数在前面补位0
    for(int i=0; i<len1-len2; i++)
        insert_elem(tempA2, 1, 0);

	// 逐位做减法.
	for(int i = a1.length-1; i >= 0; i --) {
	    // 如果不够减, 需要借位.
		if(a1.elem[i] < tempA2.elem[i])
		{
			temp = a1.elem[i] + 10;
			a1.elem[i] = temp - tempA2.elem[i];
			a1.elem[i-1] --;
		}
		// 够减就直接减.
		else a1.elem[i] -= tempA2.elem[i];
	}
	return a1;
}
# endif
