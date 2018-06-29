#include<iostream>
#include<cstdio>
#include"greatMinus.h"
#include"sqList.h"
#include"util.h"
#include "greatMultiple.h"
#include "greatMultiple.h"

using namespace std;
bool isGreater(int m , int n){
	return m > n;
}

// 辗转相减法求最大公约数, 这里m默认初始大于n
int getPrime(int m, int n){
	while (m != n){
		m = m-n;
		if (m < n)
			swap(m, n);
	}
	return m;
}

// 辗转相减法求最大公约数, 同样默认m初始大于n
// 大整数的实现

sqList greaterGetPrime(sqList m, sqList n){
    if (!isMGreaterThanN(m, n))
        swap_sq_list(m, n);
    while (!isEqual(m, n)){
        cout<<"m is : ";
        tight_print(m);
        cout<<". n is : ";
        tight_print(n);
        cout<<"."<<endl;
        m = greaterMinus(m, n);
        if (!isMGreaterThanN(m, n))
            swap_sq_list(m, n);
    }
    return m;
}


// 编写函数将一个字符创转为sq_list


int main(){
	char s1[mlen + 10];
	char s2[mlen + 10];
	scanf("%s%s",s1,s2);
    sqList m, n, result;
    init_list(m);
    init_list(n);
    init_list(result);
    m = ConvertCharArrayToSqList(s1);
    n = ConvertCharArrayToSqList(s2);
    //result = greaterGetPrime(m, n);
    //result = greaterMinus(m, n);
    result = greatMultiple(m, 2);
    //tight_print(result);
    //cout<<isMGreaterThanN(m, n);
    //tight_print(m);
    //cout<<endl;

    return 0;
}
