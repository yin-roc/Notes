//#pragma once
#ifndef __SEQLIST__H__
#define __SEQLIST__H__

#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <assert.h>

//// ��ǿ�����ά����
//#define  MAX_SIZE  10000
//typedef int SQDataType;
//// ��̬˳���
//// ���⣺�����˲����ã��������ò����˷ѣ�����������
//typedef struct SeqList
//{
//	SQDataType a[MAX_SIZE];
//	int size;
//}SL;
//
////typedef struct SeqList SL;
//
//// ��ɾ��ĵȽӿں���
//void SeqListInit(SL* ps);
//
//// ͷ�� β�� ͷɾ βɾ
//void SeqListPushBack(SL* ps, SQDataType x);
//void SeqListPushFront(SL* ps, SQDataType x);
//void SeqListPopBack(SL* ps);
//void SeqListPopFront(SL* ps);


// ��ǿ�����ά����
typedef int SQDataType;
// ��̬��
typedef struct SeqList
{
	SQDataType* a;
	int size;     // ��Ч���ݵĸ���
	int capacity; // ����
}SL;

//typedef struct SeqList SL;

// ��ɾ��ĵȽӿں���
void SeqListInit(SL* ps);
void SeqListPrint(SL* ps);
void SeqListDestory(SL* ps);

// ͷ�� β�� ͷɾ βɾ
void SeqListPushBack(SL* ps, SQDataType x);
void SeqListPushFront(SL* ps, SQDataType x);
void SeqListPopBack(SL* ps);
void SeqListPopFront(SL* ps);
void SeqListInsert(SL* ps, int pos, SQDataType x);
void SeqListErase(SL* ps, int pos);

int SeqListFind(SL* ps, SQDataType x);
void SeqListModity(SL* ps, int pos, SQDataType x);


#endif




