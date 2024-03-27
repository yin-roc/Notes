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

// ���򣬽�С�ѣ����Ǵ�ѣ�  -> ���
// ����ʱ�临�Ӷ�O(N*logN)
void HeapSort(int* a, int n)
{
	// ����  ʱ�临�Ӷȣ�O(N) 
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

// ֱ��ѡ������ʱ�临�Ӷ�O(N*N)
// �ܲ��Ϊ������Ҳ��O(N*N)
// N
// N-2
// N-4
// ...
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		int mini = begin, maxi = begin;
		for (int i = begin; i <= end; ++i)
		{
			if (a[i] < a[mini])
			{
				mini = i;
			}

			if (a[i] > a[maxi])
			{
				maxi = i;
			}
		}

		Swap(&a[begin], &a[mini]);
		// ���begin��maxi�ص�����Ҫ����һ��maxi��λ��
		if (begin == maxi)
		{
			maxi = mini;
		}
		Swap(&a[maxi], &a[end]);
		++begin;
		--end;
	}
}

void TestSelectSort()
{
	int a[] = { 9, 3, 5, 2, 7, 8, 6, -1, 9, 4, 0 };
	SelectSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

// ʱ�临�Ӷȣ�O��N*N��
// ������:O(N)
// N-1
// N-2
// ...
// ��ֱ�Ӳ���������ȣ�˭���� -�� ֱ�Ӳ������
void BubbleSort(int* a, int n)
{
	for (int j = 0; j < n; ++j)
	{
		int exchange = 0;
		for (int i = 1; i < n - j; ++i)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}

		if (exchange == 0)
		{
			break;
		}
	}

	//int end = n;
	//while (end > 0)
	//{
	//	for (int i = 1; i < end; ++i)
	//	{
	//		if (a[i - 1] > a[i])
	//		{
	//			Swap(&a[i - 1], &a[i]);
	//		}
	//	}
	//	--end;
	//}
}

void TestBubbleSort()
{
	int a[] = { 9, 3, 5, 2, 7, 8, 6, -1, 9, 4, 0 };
	BubbleSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

// ����ȡ��
int GetMidIndex(int* a, int left, int right)
{
	int mid = (left + right) >> 1;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else // a[left] > a[mid]
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}

// �ڿӷ�
int PartSort1(int* a, int left, int right)
{
	int index = GetMidIndex(a, left, right);
	Swap(&a[left], &a[index]);

	int begin = left, end = right;
	int pivot = begin;
	int key = a[begin];

	// O��N��
	while (begin < end)
	{
		// �ұ���С���ŵ����
		while (begin < end && a[end] >= key)
			--end;

		// С�ķŵ���ߵĿ���Լ��γ��µĿ�λ
		a[pivot] = a[end];
		pivot = end;

		// ����Ҵ�
		while (begin < end && a[begin] <= key)
			++begin;

		// ��ķŵ���ߵĿ���Լ��γ��µĿ�λ
		a[pivot] = a[begin];
		pivot = begin;
	}

	pivot = begin;
	a[pivot] = key;

	return pivot;
}

// �ڿӷ�
int PartSort2(int* a, int left, int right)
{
	int index = GetMidIndex(a, left, right);
	Swap(&a[left], &a[index]);

	int begin = left, end = right;
	int keyi = begin;

	while (begin < end)
	{
		// ��С
		while (begin < end && a[end] >= a[keyi])
		{
			--end;
		}

		// �Ҵ�
		while (begin < end && a[begin] <= a[keyi])
		{
			++begin;
		}

		Swap(&a[begin], &a[end]);
	}

	Swap(&a[begin], &a[keyi]);

	return begin;
}

int PartSort3(int* a, int left, int right)
{
	int index = GetMidIndex(a, left, right);
	Swap(&a[left], &a[index]);

	int keyi = left;
	int prev = left, cur = left + 1;
	while (cur <= right)
	{
		if (a[cur] < a[keyi] 
			&& ++prev != cur)
		{
			Swap(&a[prev], &a[cur]);
		}

		++cur;
	}

	Swap(&a[keyi], &a[prev]);
	return prev;
}

void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;

	int keyIndex = PartSort3(a, left, right);

	// [left, right]
	// [left, keyIndex-1] keyIndex [keyIndex+1, right]
	// ������������������������Ǿ������ˣ���������������أ� ���εݹ�

	// QuickSort(a, left, keyIndex - 1);
	// QuickSort(a, keyIndex + 1, right);

	// С����
	if (keyIndex - 1 - left > 10)
	{
		QuickSort(a, left, keyIndex - 1);
	}
	else
	{
		InsertSort(a + left, keyIndex - 1 - left + 1);
	}

	if (right - (keyIndex + 1) > 10)
	{
		QuickSort(a, keyIndex + 1, right);
	}
	else
	{
		InsertSort(a + keyIndex + 1, right - (keyIndex + 1) + 1);
	}
}

//void QuickSort(int* a, int left, int right)
//{
//	if (left >= right)
//		return;
//
//	int begin = left, end = right;
//	int pivot = begin;
//	int key = a[begin];
//
//	// ... ��������
//
//	// [left, right]
//	// [left, pivot-1] pivot [pivot+1, right]
//	// ������������������������Ǿ������ˣ���������������أ� ���εݹ�
//	QuickSort(a, left, pivot - 1);
//	QuickSort(a, pivot + 1, right);
//}

void TestQuickSort()
{
	//int a[] = { 6, 3, 5, 2, 7, 8, 9, 4, 1 };
	int a[] = { 49, 38, 65, 97, 76, 13, 27, 49, 13, 27, 49 };

	QuickSort(a, 0, sizeof(a) / sizeof(int)-1);
	PrintArray(a, sizeof(a) / sizeof(int));
}

void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
		return;

	int mid = (left + right) >> 1;
	// ���� [left, mid] [mid+1, right]
	������ô���ǾͿ��Թ鲢��
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid+1, right, tmp);

	// �鲢
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else
		{
			tmp[index++] = a[begin2++];
		}
	}

	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}

	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}
	
	// ������ȥ
	for (int i = left; i <= right; ++i)
	{
		a[i] = tmp[i];
	}
}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}

void TestMergeSort()
{
	int a[] = { 10, 6, 7 ,1, 3, 9, 4, 2 };
	MergeSort(a, sizeof(a) / sizeof(int));
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
	int* a7 = (int*)malloc(sizeof(int)*N);

	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		//a1[i] = i;
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
	}

	int begin1 = clock();
	//InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	//SelectSort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();

	int begin5 = clock();
	QuickSort(a5, 0, N - 1);
	//QuickSort(a4, 0, N - 1);
	int end5 = clock();

	int begin6 = clock();
	//MergeSort(a6, N);
	int end6 = clock();

	int begin7 = clock();
	//BubbleSort(a7, N);
	//BubbleSort(a4, N);
	int end7 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("BubbleSort:%d\n", end7 - begin7);

	printf("QuickSort:%d\n", end5 - begin5);
	/*printf("MergeSort:%d\n", end6 - begin6);*/

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a7);

}

int main()
{
	//TestOP();

	//TestShellSort();
	//TestHeapSort();
	//TestSelectSort();
	//TestBubbleSort();
	//TestQuickSort();
	TestMergeSort();

	return 0;
}