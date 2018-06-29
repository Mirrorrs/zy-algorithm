# ifndef __GREATERMINUS__H__
# define __GREATERMINUS__H__

#include<cstdio>
#include<cstring>
#include<iostream>
#include"sqList.h"
#define mlen 100

using namespace std;

sqList greaterMinus(sqList a1, sqList a2){
    int temp=0;
    int len1, len2;
    len1 = a1.length;
    len2 = a2.length;
	// 为位数不足的数在前面补位0
    for(int i=0; i<len1-len2; i++)
        insert_elem(a2, 1, 0);

	// 逐位做减法.
	for(int i = a1.length-1; i >= 0; i --) {
	    // 如果不够减, 需要借位.
		if(a1.elem[i] < a2.elem[i])
		{
			temp = a1.elem[i] + 10;
			a1.elem[i] = temp - a2.elem[i];
			a1.elem[i-1] --;
		}
		// 够减就直接减.
		else a1.elem[i] -= a2.elem[i];
	}
    // 将a2恢复为原来的位数
    for (int i=0; i<len1-len2; i++)
        delete_elem(a2, 0);
	// 撇去结果中多余的0
    int flag=0;
    for(int i=0; i<a1.length; i++)
        if(a1.elem[i]!=0){
            flag = i;
            break;
        }
    for(int i=0; i<flag; i++)
        delete_elem(a1, 0);
    return a1;
}
# endif
