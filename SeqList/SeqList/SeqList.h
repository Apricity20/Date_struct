#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

//���Ա��˳��̬�洢

//������������
typedef int SeqListDateType;

//���庯����������
typedef int status;

//����洢�ṹ
typedef struct SeqList
{
	SeqListDateType* phead;
	int size;
	int capacity;
}SeqList;

//��������

//��ʼ��
status InitSeqList(SeqList* ps);

//����
status DestorySeqList(SeqList* ps);

//���
status ClearSeqList(SeqList* ps);

//�������
status CheckCapacitySeqList(SeqList* ps);

//��ӡ
status PrintSeqList(SeqList* ps);

//β��βɾ  ͷ��ͷɾ
status SeqListPushBack(SeqList* ps, SeqListDateType x);
status SeqListPopBack(SeqList* ps);
status SeqListPushFront(SeqList* ps, SeqListDateType x);
status SeqListPopFront(SeqList* ps);

//����λ�ò���ɾ��
status SeqListInsert(SeqList* ps, int pos, SeqListDateType x);
status SeqListErase(SeqList* ps, int pos);

//����  ���ҵ��򷵻�Ԫ���±꣬���򷵻�0
status SeqListFind(SeqList* ps, SeqListDateType x);

//�޸�
status SeqListModify(SeqList* ps, int pos, SeqListDateType x);