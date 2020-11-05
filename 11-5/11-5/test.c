#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void swap(int a[], int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
int partition(int a[], int low, int high)  
{
	int pivotkey;
	pivotkey = a[low];//�����ļ�¼ֵ
	while (low < high)//��pivoekeyΪ����ý�飨���ᣩ�����������ķ��ں�ߣ�С�����ķ���ǰ��
	{
		while (low < high && a[high] >= pivotkey)//�����ж� low < high
			high--;
		swap(a, low, high);
		while (low < high && a[low] <= pivotkey)
			low++;
		swap(a, low, high);
	}
	return low;//������������λ��
}
void QSort(int a[], int low, int high)
{
	int pivot;
	if (low < high)//�� if 
	{
		pivot = partition(a, low, high);//��a[]һ��Ϊ��

		QSort(a, low, pivot - 1);//�Ե��ӱ�ݹ�����
		QSort(a, pivot + 1, high);//�Ը��ӱ�ݹ�����
	}
}
void quickSort(int a[], int low, int high)
{
	QSort(a, low, high);
}
int main()
{
	int i;
	int a[] = { 1,2,5,7,9,6,4,2,6,1 };
	quickSort(a, 0, 9);
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
