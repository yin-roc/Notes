#include <stdlib.h>
#include <stdio.h>

#include "Queue.h"

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;

	BTDataType data;
}BTNode;


void PrevOrder(BTNode* root){
	if (root == NULL){
		printf("NULL ");
		return;
	}

	printf("%c ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}

void InOrder(BTNode* root)
{
	if (root == NULL){
		printf("NULL ");
		return;
	}

	InOrder(root->left);
	printf("%c ", root->data);
	InOrder(root->right);
}

void PostOrder(BTNode* root)
{
	if (root == NULL){
		printf("NULL ");
		return;
	}

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->data);
}

//int size = 0;
//void TreeSize(BTNode* root)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//	else
//	{
//		++size;
//	}
//
//	TreeSize(root->left);
//	TreeSize(root->right);
//}

//void TreeSize(BTNode* root, int* psize)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//	else
//	{
//		++(*psize);
//	}
//
//	TreeSize(root->left, psize);
//	TreeSize(root->right, psize);
//}

int TreeSize(BTNode* root)
{
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

// 叶子节点的个数
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	if (root->left == NULL && root->right == NULL)
		return 1;

	return TreeLeafSize(root->left)
		+ TreeLeafSize(root->right);
}

void LevelOrder(BTNode* root)
{
	// 核心思路：上一层出的时候带下一层节点进
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", front->data);

		if (front->left)
		{
			QueuePush(&q, front->left);
		}

		if (front->right)
		{
			QueuePush(&q, front->right);
		}
	}
	
	printf("\n");

	QueueDestory(&q);
}


int main()
{
	BTNode* A = (BTNode*)malloc(sizeof(BTNode));
	A->data = 'A';
	A->left = NULL;
	A->right = NULL;

	BTNode* B = (BTNode*)malloc(sizeof(BTNode));
	B->data = 'B';
	B->left = NULL;
	B->right = NULL;

	BTNode* C = (BTNode*)malloc(sizeof(BTNode));
	C->data = 'C';
	C->left = NULL;
	C->right = NULL;

	BTNode* D = (BTNode*)malloc(sizeof(BTNode));
	D->data = 'D';
	D->left = NULL;
	D->right = NULL;

	BTNode* E = (BTNode*)malloc(sizeof(BTNode));
	E->data = 'E';
	E->left = NULL;
	E->right = NULL;

	A->left = B;
	A->right = C;
	B->left = D;
	B->right = E;

	PrevOrder(A);
	printf("\n");

	InOrder(A);
	printf("\n");

	PostOrder(A);
	printf("\n");

	/*TreeSize(A);
	printf("TreeSize:%d\n", size);

	size = 0;
	TreeSize(B);
	printf("TreeSize:%d\n", size);*/

	/*int Asize = 0;
	TreeSize(A, &Asize);
	printf("TreeSize:%d\n", Asize);

	int Bsize = 0;
	TreeSize(B, &Bsize);
	printf("TreeSize:%d\n", Bsize);*/


	printf("TreeSize:%d\n", TreeSize(A));

	printf("TreeSize:%d\n", TreeSize(B));

	LevelOrder(A);

	return 0;
}

///////////////////////////////////////////////////////////////////////////
// 栈实现队列OJ题代码
typedef int STDataType;
struct Stack
{
	STDataType* a;
	int top;       // 栈顶
	int capacity;  // 容量，方便增容
};

//typedef struct Stack ST;
typedef struct Stack Stack;

void StackInit(Stack* pst);
void StackDestroy(Stack* pst);

// 性质就决定在栈顶出入数据
void StackPush(Stack* pst, STDataType x);
void StackPop(Stack* pst);
STDataType StackTop(Stack* pst);

// 空返回1 非空返回0
//int StackEmpty(Stack* pst);
bool StackEmpty(Stack* pst);
int StackSize(Stack* pst);

void StackInit(Stack* pst)
{
	assert(pst);

	//pst->a = NULL;
	//pst->top = 0;
	//pst->capacity = 0;

	pst->a = (STDataType*)malloc(sizeof(STDataType) * 4);
	pst->top = 0;
	pst->capacity = 4;
}

void StackDestroy(Stack* pst)
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->capacity = pst->top = 0;
}

// 性质就决定在栈顶出入数据
void StackPush(Stack* pst, STDataType x)
{
	assert(pst);
	if (pst->top == pst->capacity)
	{
		STDataType* tmp = (STDataType*)realloc(pst->a, sizeof(STDataType)*pst->capacity * 2);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1); // 结束整个程序
		}

		pst->a = tmp;
		pst->capacity *= 2;
	}

	pst->a[pst->top] = x;
	pst->top++;
}

void StackPop(Stack* pst)
{
	assert(pst);
	assert(!StackEmpty(pst));
	pst->top--;
}

STDataType StackTop(Stack* pst)
{
	assert(pst);
	assert(!StackEmpty(pst));

	return pst->a[pst->top - 1];
}

// 空返回1 非空返回0
//int StackEmpty(Stack* pst);
bool StackEmpty(Stack* pst)
{
	assert(pst);

	return pst->top == 0;
}

int StackSize(Stack* pst)
{
	assert(pst);

	return pst->top;
}

typedef struct {
	Stack pushST;
	Stack popST;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
	MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&q->pushST);
	StackInit(&q->popST);

	return q;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	StackPush(&obj->pushST, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	/*if(StackEmpty(&obj->popST))
	{
	while(!StackEmpty(&obj->pushST))
	{
	StackPush(&obj->popST, StackTop(&obj->pushST));
	StackPop(&obj->pushST);
	}
	}
	*/

	int top = myQueuePeek(obj);
	StackPop(&obj->popST);
	return top;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	if (StackEmpty(&obj->popST))
	{
		while (!StackEmpty(&obj->pushST))
		{
			StackPush(&obj->popST, StackTop(&obj->pushST));
			StackPop(&obj->pushST);
		}
	}

	return StackTop(&obj->popST);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
	return StackEmpty(&obj->pushST) && StackEmpty(&obj->popST);
}

void myQueueFree(MyQueue* obj) {
	StackDestroy(&obj->pushST);
	StackDestroy(&obj->popST);
	free(obj);
}

/**
* Your MyQueue struct will be instantiated and called as such:
* MyQueue* obj = myQueueCreate();
* myQueuePush(obj, x);

* int param_2 = myQueuePop(obj);

* int param_3 = myQueuePeek(obj);

* bool param_4 = myQueueEmpty(obj);

* myQueueFree(obj);
*/