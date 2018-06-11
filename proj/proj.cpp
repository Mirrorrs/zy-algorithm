#include<iostream>
#include<cstdio>
#include"greaterMinus.h"
#include"sqList.h"
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

sq_list greaterGetPrime(sq_list m, sq_list n){
    if (!isMGreaterThanN(m, n))
        swap_sq_list(m, n);
    while (!isEqual(m, n)){
        getchar();
        cout<<"m is ";
        tight_print(m);
        cout<<".n is ";
        tight_print(n);
        cout<<". "<<endl;
        m = greaterMinus(m, n);
        if (!isMGreaterThanN(m, n)) {
            cout<<"m is smaller than n"<<endl;
            swap_sq_list(m, n);
        }
    }
    return m;
}


// 编写函数将一个字符创转为sq_list


int main(){
	char s1[mlen + 10];
	char s2[mlen + 10];
	scanf("%s%s",s1,s2);
    sq_list m, n, result;
    init_list(m);
    init_list(n);
    init_list(result);
    m = convert_char_array_to_sq_list(s1);
    n = convert_char_array_to_sq_list(s2);
    //result = greaterGetPrime(m, n);
    result = greaterMinus(m, n);

    //tight_print(result);
    //cout<<isMGreaterThanN(m, n);
    //tight_print(m);
    //cout<<endl;

    return 0;
}
