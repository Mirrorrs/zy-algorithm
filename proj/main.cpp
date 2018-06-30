#include <iostream>
#include <cstdio>
#include "greatMinus.h"
#include "sqList.h"
#include "util.h"
#include "greatMultiple.h"
#include "greatDivide.h"
using namespace std;
#define MAXLEN 2048
extern int steps;

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
sqList greatGetPrime(sqList m, sqList n){
    if (!isMGreaterThanN(m, n))
        SwapSqList(m, n);
    while (!isEqual(m, n)){
        m = greatMinus(m, n);
        if (!isMGreaterThanN(m, n))
            SwapSqList(m, n);
    }
    return m;
}

// 大整数求最大公约数的优化算法
// 优化上面函数中较差的情况比如10000000和1
int steps=0;
sqList greaterGetPrime(sqList m, sqList n){
    while(!isEqual(m, n)) {
        cout <<"After "<<steps++<<" steps, "<<"m is ";
        tightPrint(m);
        cout << ", n is ";
        tightPrint(n);
        cout << "." << endl;
        if (!greatIsUneven(m) && greatIsUneven(n))
            return greaterGetPrime(greatDivide(m), n);
        if (greatIsUneven(m) && !greatIsUneven(n))
            return greaterGetPrime(m, greatDivide(n));
        if (!greatIsUneven(m) && !greatIsUneven(n))
            return greatMultiple(greaterGetPrime(greatDivide(m), greatDivide(n)), 2);
        else {
            if (!isMGreaterThanN(m, n))
                SwapSqList(m, n);
            return greaterGetPrime(greatMinus(m, n), n);
        }
    }
    return m;
}

// 编写函数将一个字符创转为sq_list


int main(){
	char s1[MAXLEN + 10];
	char s2[MAXLEN + 10];
	scanf("%s%s",s1,s2);
    sqList m, n, result;
    initList(m);
    initList(n);
    initList(result);
    m = ConvertCharArrayToSqList(s1);
    n = ConvertCharArrayToSqList(s2);
    result = greaterGetPrime(m, n);
    //result = greatMinus(m, n);
    //result = greatMultiple(m, 2);
    //result = greatDivide(m);
    cout<<"Result is: ";
    tightPrint(result);
    cout<<"."<<endl;
    //cout<<isMGreaterThanN(m, n);
    //tightPrint(m);
    //cout<<endl;

    return 0;
}
