#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

//线性表的顺序动态存储

//定义数据类型
typedef int SeqListDateType;

//定义函数返回类型
typedef int status;

//定义存储结构
typedef struct SeqList
{
	SeqListDateType* phead;
	int size;
	int capacity;
}SeqList;

//基本操作

//初始化
status InitSeqList(SeqList* ps);

//销毁
status DestorySeqList(SeqList* ps);

//清空
status ClearSeqList(SeqList* ps);

//检查容量
status CheckCapacitySeqList(SeqList* ps);

//打印
status PrintSeqList(SeqList* ps);

//尾插尾删  头插头删
status SeqListPushBack(SeqList* ps, SeqListDateType x);
status SeqListPopBack(SeqList* ps);
status SeqListPushFront(SeqList* ps, SeqListDateType x);
status SeqListPopFront(SeqList* ps);

//任意位置插入删除
status SeqListInsert(SeqList* ps, int pos, SeqListDateType x);
status SeqListErase(SeqList* ps, int pos);

//查找  查找到则返回元素下标，否则返回0
status SeqListFind(SeqList* ps, SeqListDateType x);

//修改
status SeqListModify(SeqList* ps, int pos, SeqListDateType x);