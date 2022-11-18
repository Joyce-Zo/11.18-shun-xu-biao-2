#include"SeqList.h"


void TestSeqList1() 
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPrint(&sl);

	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	//SeqListPopBack(&sl);
	//SeqListPopBack(&sl);
	//SeqListPopBack(&sl);
	//SeqListPopBack(&sl);
	//SeqListPopBack(&sl);
	SeqListPrint(&sl);

	//SeqListPushBack(&sl, 1);
	//SeqListPushBack(&sl, 2);
	//SeqListPrint(&sl);


	SeqListDestory(&sl);

}
int main()
{
	TestSeqList1();
	return 0;
 }
