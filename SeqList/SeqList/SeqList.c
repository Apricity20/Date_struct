#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"


//基本操作

//初始化
status InitSeqList(SeqList* ps)
{
	//为实现动态增长，初始化先设置两个空间
	ps->phead = (SeqListDateType*)malloc(2 * sizeof(SeqListDateType));
	if (ps->phead == NULL)
	{
		perror("InitSeqList");
		return ERROR;
	}
	ps->size = 0;
	ps->capacity = 2;

	return OK;
}

//销毁
status DestorySeqList(SeqList* ps)
{
	free(ps->phead);
	ps->phead = NULL;
	ps->size = 0;
	ps->capacity = 0;

	return OK;
}

//清空  返回当前容量
status ClearSeqList(SeqList* ps)
{
	ps->size = 0;
	//返回当前的容量
	return ps->capacity;
}

//检查容量
status CheckCapacitySeqList(SeqList* ps)
{
	//判断是否需要增容
	if (ps->size == ps->capacity)
	{
		ps->capacity *= 2;
		SeqListDateType* temp = realloc(ps->phead, ps->capacity * sizeof(SeqListDateType));
		if (temp == NULL)
		{
			perror("CheckCapacitySeqList");
			return ERROR;
		}
		ps->phead = temp;
	}
	return OK;
}

//打印
status PrintSeqList(SeqList* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%3d ", ps->phead[i]);
	}
	printf("\n");
	return OK;
}

//尾插尾删  头插头删
status SeqListPushBack(SeqList* ps, SeqListDateType x)
{
	SeqListInsert(ps, ps->size, x);
	return OK;

}

status SeqListPopBack(SeqList* ps)
{
	SeqListErase(ps, ps->size-1);
	return OK;

}

status SeqListPushFront(SeqList* ps, SeqListDateType x)
{
	SeqListInsert(ps, 0, x);
	return OK;

}

status SeqListPopFront(SeqList* ps)
{
	SeqListErase(ps, 0);
	return OK;

}

//任意位置插入删除
status SeqListInsert(SeqList* ps, int pos, SeqListDateType x)
{
	//检查容量
	CheckCapacitySeqList(ps);

	//判断插入位置合法性
	if (pos<0 || pos>ps->size)
	{
		return ERROR;
	}
	//向后挪动元素
	int tail = ps->size;
	while (tail > pos)
	{
		ps->phead[tail] = ps->phead[tail - 1];
		tail--;
	}
	//插入元素
	ps->phead[pos] = x;

	ps->size++;
	return OK;

}

status SeqListErase(SeqList* ps, int pos)
{
	//判断位置合法性
	if (pos<0 || pos>ps->size - 1)
	{
		perror("SeqListErase");
		return ERROR;
	}
	//向前挪动元素
	int head = pos;
	while (head < ps->size)
	{
		ps->phead[head] = ps->phead[head + 1];
		head++;
	}

	ps->size--;
	return OK;
}

//查找  查找到则返回元素下标，否则返回-1
status SeqListFind(SeqList* ps, SeqListDateType x)
{
	int start = 0;
	for (start = 0; start < ps->size; start++)
	{
		if (ps->phead[start] == x)
			return start;
	}

	return -1;
}

//修改  可以使用函数指针作为参数与查找函数配合
status SeqListModify(SeqList* ps, int pos, SeqListDateType x)
{
	//检查位置合法性
	if (pos < 0 || pos >= ps->size)
	{
		perror("SeqListModify");
		return ERROR;
	}
	ps->phead[pos] = x;
	return OK;
}