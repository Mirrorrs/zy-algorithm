//
// Created by ma on 18-6-29.
//

#ifndef __SQLIST__H__
#define __SQLIST__H__

#include <iostream>
using namespace std;
#include <cstdio>
#include <cstdlib>
#include <malloc.h>
#define True 1
#define False 0
#define OVERFLOW -2
#define init_size 2048
#define extra_size 2048
typedef int Status;

typedef struct{
	int* elem;
	int length;
	int list_size;
	}sqList;


//初始化线性表
Status initList(sqList &L);

// 创建线性表
// L为线性表, e为元素值.
void appendList(sqList &L, int e);


// 插入元素, 在位置i之前.
// 位置为下标+1
Status insertElem(sqList &L, int i, int e);

//删除元素
//i为下标+1
void deleteElem(sqList &L, int i);

// 打印整个列表
void print(sqList L);

// 没有空格地打印
void tightPrint(sqList L);

// 比较两个线性表表示的数的大小
Status isMGreaterThanN(sqList m, sqList n);

// 比较两个列表是否完全相等
Status isEqual(sqList L1, sqList L2);

// 交换两个线性表
void SwapSqList(sqList &m, sqList &n);


Status initList(sqList &L) {
    L.elem = (int*)malloc(init_size*sizeof(int));
    if (!L.elem) exit(OVERFLOW);
    L.length = 0;
    L.list_size = init_size;
    return True;
}

void appendList(sqList &L, int e) {
    L.elem[L.length++] = e;
}

void deleteElem(sqList &L, int i) {
    for (int j = i-1;j < L.length;j++)
        L.elem[j] = L.elem[j+1];
    L.length--;
}

Status insertElem(sqList &L, int i, int e) {
    // 两种异常的处理
    if (i<1||i>L.length + 1){return False;}
    if (L.length>=L.list_size){
        int* newbase = (int*)realloc(L.elem,
                                     (L.list_size + extra_size)*sizeof(int));
        L.elem = newbase;
        L.list_size += extra_size;
    }
    //为新元素腾出空间
    L.length ++;
    // 为新元素挪位置
    for (int j = L.length;j >= i;j--) L.elem[j] = L.elem[j-1];
    L.elem[i-1] = e;
    return True;
}

void print(sqList L) {
    for (int i=0;i<L.length;i++)
        printf("%d ",L.elem[i]);
    printf("\n");
}

void tightPrint(sqList L) {
    for (int i=0; i < L.length; i ++)
        printf("%d", L.elem[i]);
}


Status isMGreaterThanN(sqList m, sqList n) {
    if (m.length > n.length)
        return True;
    else if (m.length < n.length)
        return False;
    else
        for(int i=0; i<m.length; i++)
            if (m.elem[i] > n.elem[i])
                return True;
            else if (m.elem[i] == n.elem[i])
                continue;
            else
                return False;
}

Status isEqual(sqList L1, sqList L2) {
    if (L1.length != L2.length) return False;
    else{
        int iterRound = L1.length;
        for(int i=0; i < iterRound; i ++){
            if (L1.elem[i] != L2.elem[i])
                return False;
        }
        return True;
    }
}

void SwapSqList(sqList &m, sqList &n) {
    sqList temp;
    initList(temp);
    temp = m;
    m = n;
    n = temp;
}

#endif
