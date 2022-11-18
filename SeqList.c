#pragma once

#include "SeqList.h"

// ��ʼ��
void SeqListInit(SL*ps)
{
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

// ����˳���
void SeqListDestory(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}

// β������
void SeqListPushBack(SL* ps, SLDataType x)
{
	SeqListCheckCapacity(ps);
	ps->a[ps->size] = x; // Ҫ����ֵ���ṹ��
	ps->size++;
}

// ��ӡ˳���
void SeqListPrint(SL* ps)
{
	int i = 0;
	for (i; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

// ��鲢����
void SeqListCheckCapacity(SL* ps)
{
	//  ���û�пռ�(0��)��ռ䲻��(����)
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		//  ��Ŀ������ �Ƿ����0���Ǹ�4�������2��ԭ�ռ�
		SLDataType* tmp = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * newcapacity);
		//	���ٿռ�
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);	// �쳣��ֹ����
		}
		ps->a = tmp;	//	���ٵĿռ���ṹ��
		ps->capacity = newcapacity;// ���ٵĴ�С��ԭ��С
	}
}

// βɾ����
void SeqListPopBack(SL* ps)
{
	//	1.
	//if (ps->size > 0)
	//{
	//	//ps->a[ps->size - 1] = 0;   ���ﲻ��д������ֱ��size--����Ч���ݼ���
	//	ps->size--;
	//}
	//  2.
	assert(ps->size > 0);
	ps->size--;

}

//	ͷ������
void SeqListPushFront(SL* ps, SLDataType x)
{
	// �ж�+����
	SeqListCheckCapacity(ps);
	// Ų�����ݣ��Ӻ���ǰ
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	// ��������
	ps->a[0] = x;
	ps->size++;
}

// ͷɾ����
void SeqListPopFront(SL* ps)
{
	assert(ps->size > 0);

	int begin = 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		begin++;
	}
	ps->size--;
}

