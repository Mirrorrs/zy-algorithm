# ifndef __GREATERMINUS__H__
# define __GREATERMINUS__H__

#include<cstdio>
#include<cstring>
#include<iostream>
#include"sqList.h"
#define mlen 200

using namespace std;

// 编写一个函数将字符串转为线性表
sq_list convert_char_array_to_sq_list(char* s){
    sq_list result;
    init_list(result);
    int len = strlen(s);
    for (int i=len-1; i>=0; i--) append_list(result, s[i]-'0');
    return result;
}


sq_list greaterMinus(sq_list a1, sq_list a2){
    /*
    sq_list a1, a2;
    init_list(a1);init_list(a2);
	int i,j,k;
	//j=0;
	//for(i=len1-1;i>=0;i--) append_list(a1, s1[i]-'0');
    a1 = convert_char_array_to_sq_list(s1);

	// 同上处理第二个数.
	//int len2=strlen(s2);
	//j=0;
	//for(i=len2-1;i>=0;i--) append_list(a2, s2[i]-'0');
    a2 = convert_char_array_to_sq_list(s2);
    */
	int temp=0;
	// 逐位做减法.
	for(int i = 0; i < mlen; i ++)
	{
		// 如果不够减, 需要借位.
		if(a1.elem[i] < a2.elem[i])
		{
			temp = a1.elem[i] + 10;
			a1.elem[i] = temp - a2.elem[i];
			a1.elem[i+1] --;
		}
		// 够减就直接减.
		else a1.elem[i] -= a2.elem[i];
	}
    print(a1);
    // 目前为止, 在a1中存放的是结果的倒序, 我们将它保存到result中并带回.
    sq_list result;
    init_list(result);
    int flag;
    for(int i=a1.length - 1; i >= 0; i--)
        if(a1.elem[i]!=0){
            flag = i;
            break;
        }
    cout<<flag<<endl;
    for(int i = flag; i >=0; i--)
        append_list(result, a1.elem[i]);
    return result;
}
# endif
