#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

void Swap(int *arr, int x, int y)
{
	int tmp = arr[x];
	arr[x] = arr[y];
	arr[y] = tmp;
}

//��������
void Insort(int* arr, int n)
{
	for (int i = 1; i < n; i++)
	{
		//���һ������λ��
		int end = i - 1;
		int data = arr[i];
		while (end >= 0 && arr[end] > data)
		{
			arr[end + 1] = arr[end];
			--end;
		}
		arr[end + 1] = data;
	}
}

//ϣ������
void Shell_sort(int* arr, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = gap; i < n; i++)
		{
			int end = i - gap;
			int data = arr[i];
			while (end >= 0 && arr[end] > data)
			{
				arr[end + gap] = arr[end];
				end-=gap;
			}
			arr[end + gap] = data;
		}
	}
}




////ѡ������-1
//void Select_insert1(int *arr, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		int k = i;
//		for (int j = i + 1; j < n; j++)
//		{
//			if (arr[j] < arr[k])
//				k = j;
//		}
//		if (k != i)
//		{
//			int tmp = arr[k];
//			arr[k] = arr[i];
//			arr[i] = tmp;
//		}
//	}
//}

//ѡ������-2
void Select_insert2(int *arr, int n)
{
	int start = 0;
	int end = n - 1 ;
	while (start < end)
	{ 
		int min = start;
		int max = start;
		for (int j = start + 1; j <= end; j++)
		{
			if (arr[j] < arr[min])
				min = j;
			if (arr[j] > arr[max])
				max = j;
		}
		Swap(arr, start, min);
		if (max == start)
			max = min;
		Swap(arr, end, max);
		start++;
		end--;
	}
}


void Select_insert_test()
{
	int arr[] = { 9,5,6,4,8,7,3,2,1 };
	Shell_sort(arr, 9);
	for (int i = 0; i < 9; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	Select_insert_test();
	return 0;
}