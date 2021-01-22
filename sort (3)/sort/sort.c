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

//ð������-1
void bubble_sort(int *arr, int sz)
{
	int end = sz;
	while (end > 0)
	{
		for (int i = 0; i < end - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				int tmp = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = tmp;
			}
		}
		end--;
	}

	//ð������-2
	//int i = 0;
	//for (i = 0; i < sz - 1; i++)
	//{
	//	int j = 0;
	//	for (j = 0; j < sz - 1 - i; j++)
	//	{
	//		if (arr[j] > arr[j + 1])
	//		{
	//			int tmp = arr[j];
	//			arr[j] = arr[j + 1];
	//			arr[j + 1] = tmp;
	//		}
	//	}
	//}
}

//���������ȡ��׼ֵ--����ȡ�з�
int  getmid(int *arr,int begin,int end)
{
	int mid = (begin + end) / 2;
	if (arr[begin] > arr[mid])
	{
		if (arr[mid] > arr[end])
			return mid;
		else if (arr[begin] > arr[end])
			return end;
		else
			return begin;
	}
	else
	{
		if (arr[end] < arr[begin])
			return begin;
		else if (arr[mid] > arr[end])
			return end;
		else
			return mid;
	}
}
//��������---Hoare
//��������--���麯�������ػ�׼ֵ���ڵ�λ��
int Partion_Hoare(int *arr, int begin, int end)
{
	//��ȡ��׼ֵ----�������д��Ż����ܻᵼ�º���ջ���
	int mid = getmid(arr, begin, end);
	//����׼ֵ����beginλ��
	Swap(arr, begin, mid);
	//�����׼ֵ��λ��
	int start = begin;
	while (begin < end)
	{
		//�ȴӺ���ǰ�ҽ�Сֵ
		while (begin<end&&arr[end] >= arr[start])
			end--;
		//�ٴ�ǰ����ҽϴ�ֵ
		while (begin<end&&arr[begin] <= arr[start])
			begin++;
		//����    ���ڻ�׼ֵ�ķ��ں��棬С�ķ���ǰ��
		Swap(arr, begin, end);
	}
	//����׼ֵ�����м䣬��ʱ��ߵ�ֵС�ڻ�׼ֵ���ұߴ��ڻ�׼ֵ
	Swap(arr, start, begin);
	//���ؽ�����Ļ�׼ֵ��λ��
	return begin;
}

//��������--�ݹ�ʵ��--Hoare
void Quick_sort_Hoare(int *arr, int begin, int end)
{
	if (begin >= end)
		return;

		int cur = Partion_Hoare(arr, begin, end);
		Quick_sort_Hoare(arr, begin, cur - 1);
		Quick_sort_Hoare(arr, cur + 1, end);
	
	
}

//��������--��ӷ�
//��һ��λ��Ϊ��ʼ�ӵ�λ��
int  Partion_tk(int *arr, int begin, int end)
{
	//������׼ֵ
	int mid = getmid(arr, begin, end);
	Swap(arr, begin, mid);

	int key = arr[begin];
	while (begin < end)
	{
		//�Ӻ���ǰ��С��
		while (begin < end&&arr[end] >= key)
			--end;
		//���
		arr[begin] = arr[end];
		//��ǰ����Ҵ��
		while (begin < end&&arr[begin] <= key)
			++begin;
		//���
		arr[end] = arr[begin];
	}
	arr[begin] = key;
	return begin;
}

//��������--��ӷ�
void Quick_sort_tk(int *arr, int begin, int end)
{
	if (begin >= end)
		return;

	int cur = Partion_tk(arr, begin, end);
	Quick_sort_tk(arr, begin, cur - 1);
	Quick_sort_tk(arr, cur + 1, end);

}


//�����������--ǰ��ָ�뷨
int Partion_qh(int * arr, int begin, int end)
{
	//������׼ֵ
	int mid = getmid(arr, begin, end);
	Swap(arr, begin, mid);

	int prev = begin;
	int cur = begin + 1;
	int key = arr[begin];
	while (cur <= end)
	{
		if (arr[cur]<key&&++prev != cur)
			Swap(arr, prev, cur);
		else 
		++cur;

	}
	Swap(arr, begin, prev);
	return prev;
}

//��������--ǰ��ָ�뷨
void Quick_sort_qh(int *arr, int begin, int end)
{
	if (begin >= end)
		return;

	int cur = Partion_qh(arr, begin, end);
	Quick_sort_qh(arr, begin, cur - 1);
	Quick_sort_qh(arr, cur + 1, end);

}


//ѡ������-1
void Select_insert1(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		int k = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[k])
				k = j;
		}
		if (k != i)
		{
			Swap(arr, k, i);
		}
	}
}

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


void test()
{
	int arr[] = { 9,5,6,4,8,7,3,2,1 };   //9����
	for (int i = 0; i < 9; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	Select_insert1(arr, 9);
	for (int i = 0; i < 9; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	test();
	return 0;
}