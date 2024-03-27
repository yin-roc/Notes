#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// ���趼������������������Ƿ�����

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

// ��������
// ʱ�临�Ӷ��Ƕ��٣�O(N^2)
// ʲô������������  1+2+3+...+n-1
// ʲô�������ã�˳������  O(N)
void InsertSort(int* a, int n)
{
	// [0, end]����  end+1λ�õ�ֵ����[0, end]����[0, end+1]����
	for (int i = 0; i < n-1; ++i)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

void TestInsertSort()
{
	int a[] = { 3, 5, 2, 7, 8, 6, 1, 9, 4, 0 };
	InsertSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

// ֱ�Ӳ�������Ļ����ϵ��Ż�
// 1���Ƚ���Ԥ����������ӽ�����
// 2��ֱ�Ӳ�������
// ʱ�临�Ӷȣ�O(logN*N) ���� O(log3N*N)
// ƽ����ʱ�临�Ӷ���O(N^1.3)
void ShellSort(int* a, int n)
{
	int gap = n;

	while (gap > 1)
	{
		//gap = gap / 2;  // logN
		gap = gap / 3 + 1; // log3N ��3Ϊ�����Ķ���
		// gap > 1ʱ����Ԥ����  �ӽ�����
		// gap == 1ʱ����ֱ�Ӳ������� ����

		// gap�ܴ�ʱ������Ԥ����ʱ�临�Ӷ�O(N)
		// gap��Сʱ�������Ѿ��ܽӽ������ˣ���ʱ���Ҳ��(N)

		// �Ѽ��Ϊgap�Ķ�������ͬʱ��
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}	
}

void TestShellSort()
{
	int a[] = { 3, 5, 2, 7, 8, 6, 1, 9, 4, 0 };
	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustDwon(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1; // Ĭ��������
	while (child < n)
	{
		// 1��ѡ�����Һ����д����һ��
		if (child + 1 < n && a[child+1] > a[child])
		{
			child += 1;
		}

		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* a, int n)
{
	// ����  O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDwon(a, n, i);
	}

	// �����򣬽���ѻ���С�ѣ������
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);
		--end;
	}
}

void TestHeapSort()
{
	int a[] = { 3, 5, 2, 7, 8, 6, 1, 9, 4, 0 };
	HeapSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

// ������������ܶԱ�
void TestOP()
{
	srand(time(0));
	const int N = 1000000;
	int* a1 = (int*)malloc(sizeof(int)*N);
	int* a2 = (int*)malloc(sizeof(int)*N);
	int* a3 = (int*)malloc(sizeof(int)*N);
	int* a4 = (int*)malloc(sizeof(int)*N);
	int* a5 = (int*)malloc(sizeof(int)*N);
	int* a6 = (int*)malloc(sizeof(int)*N);

	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];

	}

	int begin1 = clock();
	InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	//SelectSort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	//HeapSort(a4, N);
	int end4 = clock();

	int begin5 = clock();
	//QuickSort(a5, 0, N - 1);
	int end5 = clock();

	int begin6 = clock();
	//MergeSort(a6, N);
	int end6 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	/*printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("QuickSort:%d\n", end5 - begin5);
	printf("MergeSort:%d\n", end6 - begin6);*/

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
}

int main()
{
	//TestShellSort();
	//TestOP();
	TestHeapSort();

	return 0;
}