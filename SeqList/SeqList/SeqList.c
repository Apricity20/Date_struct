#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"


//��������

//��ʼ��
status InitSeqList(SeqList* ps)
{
	//Ϊʵ�ֶ�̬��������ʼ�������������ռ�
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

//����
status DestorySeqList(SeqList* ps)
{
	free(ps->phead);
	ps->phead = NULL;
	ps->size = 0;
	ps->capacity = 0;

	return OK;
}

//���  ���ص�ǰ����
status ClearSeqList(SeqList* ps)
{
	ps->size = 0;
	//���ص�ǰ������
	return ps->capacity;
}

//�������
status CheckCapacitySeqList(SeqList* ps)
{
	//�ж��Ƿ���Ҫ����
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

//��ӡ
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

//β��βɾ  ͷ��ͷɾ
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

//����λ�ò���ɾ��
status SeqListInsert(SeqList* ps, int pos, SeqListDateType x)
{
	//�������
	CheckCapacitySeqList(ps);

	//�жϲ���λ�úϷ���
	if (pos<0 || pos>ps->size)
	{
		return ERROR;
	}
	//���Ų��Ԫ��
	int tail = ps->size;
	while (tail > pos)
	{
		ps->phead[tail] = ps->phead[tail - 1];
		tail--;
	}
	//����Ԫ��
	ps->phead[pos] = x;

	ps->size++;
	return OK;

}

status SeqListErase(SeqList* ps, int pos)
{
	//�ж�λ�úϷ���
	if (pos<0 || pos>ps->size - 1)
	{
		perror("SeqListErase");
		return ERROR;
	}
	//��ǰŲ��Ԫ��
	int head = pos;
	while (head < ps->size)
	{
		ps->phead[head] = ps->phead[head + 1];
		head++;
	}

	ps->size--;
	return OK;
}

//����  ���ҵ��򷵻�Ԫ���±꣬���򷵻�-1
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

//�޸�  ����ʹ�ú���ָ����Ϊ��������Һ������
status SeqListModify(SeqList* ps, int pos, SeqListDateType x)
{
	//���λ�úϷ���
	if (pos < 0 || pos >= ps->size)
	{
		perror("SeqListModify");
		return ERROR;
	}
	ps->phead[pos] = x;
	return OK;
}