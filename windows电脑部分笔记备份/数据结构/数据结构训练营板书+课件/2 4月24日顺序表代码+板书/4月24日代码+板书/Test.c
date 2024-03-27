#include "SeqList.h"

void TestSeqList1()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPushBack(&sl, 6);
	SeqListPushBack(&sl, 7);
	SeqListPushBack(&sl, 8);
	SeqListPushBack(&sl, 9);
	SeqListPushBack(&sl, 10);
	SeqListPushBack(&sl, 11);
	SeqListPushBack(&sl, 11);
	SeqListPushBack(&sl, 11);
	SeqListPushBack(&sl, 11);
	SeqListPushBack(&sl, 11);
	SeqListPushBack(&sl, 11);
	SeqListPushBack(&sl, 11);
	SeqListPushBack(&sl, 11);
	SeqListPushBack(&sl, 11);
	SeqListPushBack(&sl, 11);
	SeqListPushBack(&sl, 11);
	SeqListPushBack(&sl, 11);
	SeqListPushBack(&sl, 11);
	SeqListPushBack(&sl, 11);
	SeqListPushBack(&sl, 11);
	SeqListPushBack(&sl, 11);
	SeqListPushBack(&sl, 11);
	SeqListPrint(&sl);

	SeqListDestory(&sl);
}

void TestSeqList2()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushFront(&sl, 1);
	SeqListPushFront(&sl, 2);
	SeqListPushFront(&sl, 3);
	SeqListPushFront(&sl, 4);
	SeqListPushFront(&sl, 5);
	SeqListPushFront(&sl, 6);
	SeqListPrint(&sl);

	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPrint(&sl);

	SeqListPopFront(&sl);
	SeqListPrint(&sl);

	SeqListDestory(&sl);
}

void TestSeqList3()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushFront(&sl, 1);
	SeqListPushFront(&sl, 2);
	SeqListPushFront(&sl, 3);
	SeqListPushFront(&sl, 4);
	SeqListPushFront(&sl, 5);
	SeqListPushFront(&sl, 6);
	SeqListPrint(&sl);
	SeqListInsert(&sl, 1, 20);
	SeqListPrint(&sl);

	SeqListErase(&sl, 1);
	SeqListPrint(&sl);

	SeqListDestory(&sl);
}

void menu()
{
	printf("**********************************************\n");
	printf("1.β�����ݣ� 2.ͷ������\n");
	printf("3.βɾ���ݣ� 4.ͷɾ����\n");
	printf("5.��ӡ���ݣ�-1.�˳�\n");
	printf("**********************************************\n");
	printf("�����������ѡ��:");
}

int main()
{
	SL s;
	SeqListInit(&s);
	int option = 0;
	int x = 0;
	while (option != -1)
	{
		menu();
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			printf("��������Ҫ��������ݣ���-1����\n");
			do {
				scanf("%d", &x);
				if (x != -1)
				{
					SeqListPushBack(&s, x);
				}
			} while (x != -1);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			SeqListPrint(&s);
			break;
		default:
			break;
		}
	}

	SeqListDestory(&s);

	return 0;
}