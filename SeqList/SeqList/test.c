#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

void TestSeqList1()
{
	SeqList s;
	//��ʼ��
	InitSeqList(&s);
	//����
	SeqListInsert(&s, 0, 1);
	SeqListInsert(&s, 0, 2);
	SeqListInsert(&s, 0, 3);
	SeqListInsert(&s, 0, 4);
	SeqListInsert(&s, 0, 5);
	PrintSeqList(&s);

	//DestorySeqList(&s);
	//PrintSeqList(&s);

	//int length = ClearSeqList(&s);
	//printf("%d\n", length);

	SeqListErase(&s, 0);
	SeqListErase(&s, 3);
	PrintSeqList(&s);

}

void TestSeqList2()
{
	SeqList s;
	//��ʼ��
	InitSeqList(&s);
	//β��
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	PrintSeqList(&s);

	//βɾ
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	PrintSeqList(&s);

	//ͷ��
	SeqListPushFront(&s, -1);
	SeqListPushFront(&s, -2);
	PrintSeqList(&s);

	//β��
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	PrintSeqList(&s);

}

void TestSeqList3()
{
	SeqList s;
	//��ʼ��
	InitSeqList(&s);
	//β��
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	PrintSeqList(&s);

	//����
	int pos = SeqListFind(&s, 5);
	printf("%3d\n", pos);

	//�޸�
	SeqListModify(&s, pos, 0);
	PrintSeqList(&s);

}

int main()
{
	TestSeqList3();

	return 0;
}