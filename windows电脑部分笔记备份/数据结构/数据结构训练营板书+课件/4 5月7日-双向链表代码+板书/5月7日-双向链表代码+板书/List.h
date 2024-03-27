#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


//typedef char LTDataType;
typedef int LTDataType;

// SList
// DList

// ��ͷ˫��ѭ�� -- ��������ṹ������λ�ò���ɾ�����ݶ���O(1)
typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}ListNode;

ListNode* ListInit();
void ListDestory(ListNode* phead);
void ListPrint(ListNode* phead);

void ListPushBack(ListNode* phead, LTDataType x);
void ListPushFront(ListNode* phead, LTDataType x);
void ListPopFront(ListNode* phead);
void ListPopBack(ListNode* phead);

ListNode* ListFind(ListNode* phead, LTDataType x);
// posλ��֮ǰ����x
void ListInsert(ListNode* pos, LTDataType x);
// ɾ��posλ�õ�ֵ
void ListErase(ListNode* pos);

bool ListEmpty(ListNode* phead);
int ListSize(ListNode* phead);