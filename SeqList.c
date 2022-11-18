#pragma once

#include "SeqList.h"

// 初始化
void SeqListInit(SL*ps)
{
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

// 销毁顺序表
void SeqListDestory(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}

// 尾插数据
void SeqListPushBack(SL* ps, SLDataType x)
{
	SeqListCheckCapacity(ps);
	ps->a[ps->size] = x; // 要传的值给结构体
	ps->size++;
}

// 打印顺序表
void SeqListPrint(SL* ps)
{
	int i = 0;
	for (i; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

// 检查并扩容
void SeqListCheckCapacity(SL* ps)
{
	//  如果没有空间(0个)或空间不足(满了)
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		//  三目操作符 是否等于0，是给4，否则给2倍原空间
		SLDataType* tmp = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * newcapacity);
		//	开辟空间
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);	// 异常终止程序
		}
		ps->a = tmp;	//	开辟的空间给结构体
		ps->capacity = newcapacity;// 开辟的大小给原大小
	}
}

// 尾删数据
void SeqListPopBack(SL* ps)
{
	//	1.
	//if (ps->size > 0)
	//{
	//	//ps->a[ps->size - 1] = 0;   这里不用写，下面直接size--，有效数据减少
	//	ps->size--;
	//}
	//  2.
	assert(ps->size > 0);
	ps->size--;

}

//	头插数据
void SeqListPushFront(SL* ps, SLDataType x)
{
	// 判断+扩容
	SeqListCheckCapacity(ps);
	// 挪动数据，从后往前
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	// 插入数据
	ps->a[0] = x;
	ps->size++;
}

// 头删数据
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

