
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>

typedef char STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

void StackInit(ST* ps);
void StackDestory(ST* ps);
// 入栈
void StackPush(ST* ps, STDataType x);
// 出栈
void StackPop(ST* ps);
STDataType StackTop(ST* ps);

int StackSize(ST* ps);
bool StackEmpty(ST* ps);

void StackInit(ST* ps)
{
	assert(ps);

	ps->a = (STDataType*)malloc(sizeof(STDataType) * 4);
	if (ps->a == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}

	ps->capacity = 4;
	ps->top = 0;
}

void StackDestory(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}

// 入栈
void StackPush(ST* ps, STDataType x)
{
	assert(ps);

	// 满了-》增容
	if (ps->top == ps->capacity)
	{
		STDataType* tmp = (STDataType*)realloc(ps->a, ps->capacity * 2 * sizeof(STDataType));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		else
		{
			ps->a = tmp;
			ps->capacity *= 2;
		}
	}

	ps->a[ps->top] = x;
	ps->top++;
}

// 出栈
void StackPop(ST* ps)
{
	assert(ps);
	// 栈空了，调用Pop，直接中止程序报错
	assert(ps->top > 0);

	//ps->a[ps->top - 1] = 0;
	ps->top--;
}

STDataType StackTop(ST* ps)
{
	assert(ps);
	// 栈空了，调用Top，直接中止程序报错
	assert(ps->top > 0);

	return ps->a[ps->top - 1];
}

int StackSize(ST* ps)
{
	assert(ps);

	return ps->top;
}

bool StackEmpty(ST* ps)
{
	assert(ps);

	return ps->top == 0;
}

bool isValid(char * s){
	ST st;
	StackInit(&st);
	while (*s != '\0')
	{
		switch (*s)
		{
		case '{':
		case '[':
		case '(':
		{
			StackPush(&st, *s);
			++s;
			break;
		}
		case '}':
		case ']':
		case ')':
		{
			if (StackEmpty(&st))
			{
				StackDestory(&st);
				return false;
			}

			char top = StackTop(&st);
			StackPop(&st);

			// 不匹配
			if ((*s == '}' && top != '{')
				|| (*s == ']' && top != '[')
				|| (*s == ')' && top != '('))
			{
				StackDestory(&st);
				return false;
			}
			else // 匹配
			{
				++s;
			}
			break;
		}
		default:
			break;
		}
	}

	bool ret = StackEmpty(&st);
	StackDestory(&st);
	return ret;
}

//int main()
//{
//	//printf("%d", isValid("[[["));
//	// 调试接口型OJ题，快速构建链表测试·
//	ListNode* l1;
//
//	ListNode* n1 = (ListNode*)malloc(sizeof(ListNode));
//	n1->val = 1;
//	ListNode* n2 = (ListNode*)malloc(sizeof(ListNode));
//	n1->val = 1;
//	ListNode* n3 = (ListNode*)malloc(sizeof(ListNode));
//	n1->val = 1;
//
//	l1 = n1;
//	n1->next = n2;
//	n2->next = n3;
//	n2->next = NULL;
//
//
//	ReverseList(l1);
//
//	return 0;
//}
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
		return;}

	printf("%c ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}

void InOrder(BTNode* root)
{

}

void PostOrder(BTNode* root)
{

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


	return 0;
}













