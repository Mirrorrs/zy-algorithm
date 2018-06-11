#ifndef __SQLIST__H__
#define __SQLIST__H__
#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define True 1
#define False 0
#define OVERFLOW -2
#define init_size 100
#define extra_size 100
typedef int Status;
typedef struct{
	int* elem;
	int length;
	int list_size;
	}sq_list;

//初始化线性表
Status init_list(sq_list &L){
	L.elem = (int*)malloc(init_size*sizeof(int));
	if (!L.elem) exit(OVERFLOW);
	L.length = 0;
	L.list_size = init_size;
	return True;
	}

// 创建线性表
// L为线性表, e为元素值.
void append_list(sq_list &L, int e){
	L.elem[L.length++] = e;
	}


// 插入元素, 在位置i之前.
// 位置为下标+1
Status insert_elem(sq_list &L,int i,int e){
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

//删除元素
//i为下标+1
void delete_elem(sq_list &L,int i){
	for (int j = i-1;j < L.length;j++)
		L.elem[j] = L.elem[j+1];
	L.length--;
	}
// 打印整个列表
void print(sq_list L){
	for (int i=0;i<L.length;i++)
		printf("%d ",L.elem[i]);
	printf("\n");
	}

// 没有空格地打印
void tight_print(sq_list L){
    for (int i=0; i < L.length; i ++)
        printf("%d", L.elem[i]);
}

// 清空列表
sq_list clean_list(sq_list L){
    free(L.elem);
    init_list(L);
    return L;
}

// 清空列表, 将后一个列表的值完全赋给前一个列表
sq_list extend_list(sq_list result, sq_list toGive){
    clean_list(result);
    init_list(result);
    cout<<endl;
    for(int i = 0; i < toGive.length; i ++)
        append_list(result, toGive.elem[i]);
    return result;
}
// 比较两个线性表表示的数的大小
Status isMGreaterThanN(sq_list m, sq_list n){
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

// 比较两个列表是否完全相等
Status isEqual(sq_list L1, sq_list L2){
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

// 复制一个前一个线性表给后一个
void cp_sq_list(sq_list L1, sq_list L2){
    for(int i=0; i<L1.length; i++)
        append_list(L2, L2.elem[i]);
}

// 交换两个线性表
void swapp_sq_list(sq_list &m, sq_list &n){
    int stdLength = m.length<n.length?m.length:n.length;
    int i = 0;
    for(i; i<stdLength; i++)
        swap(m.elem[i], n.elem[i]);
    if (m.length>=n.length){
        int lengthForM = n.length;
        for(int j=i; j<m.length; j++)
            append_list(n, m.elem[j]);
        m.length = lengthForM;
    }
    else{
        int lengthForN = m.length;
        for(int j=i; j<n.length; j++)
            append_list(m, n.elem[j]);
        n.length = lengthForN;
    }
}

void swap_sq_list(sq_list &m, sq_list &n){
    sq_list temp;
    init_list(temp);
    temp = m;
    m = n;
    n = temp;
}


#endif
