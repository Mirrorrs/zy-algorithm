#include <iostream>
#include <cstdio>
#include <ctime>
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
        cout <<"After "<<++steps<<" steps, "<<"m is ";
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
    // 声明变量以及初始化
    char* s1; char* s2;
	clock_t start, end;
	double cost;
    sqList m, n, result;
    initList(m); initList(n); initList(result);

    // 读取文件并赋值给待操作数
    char in1[20] = {"../in1.in"};
    char in2[20] = {"../in2.in"};
    char out[20] = {"../out.out"};
    s1 = readFromFile(in1);
    s2 = readFromFile(in2);

    // 讲字符串转线性表
    m = ConvertCharArrayToSqList(s1);
    n = ConvertCharArrayToSqList(s2);

    // 算法计时开始
    start = clock();
    // 传入参数计算GCD
    result = greaterGetPrime(m, n);
    // 算法计时结束
    end = clock();
    cost = (double)(end - start) / CLOCKS_PER_SEC;

    // 打印相关信息并输入到文件
    generateResult(result, steps, cost);

    return 0;
}
