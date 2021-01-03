#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//���µ����㷨---����С��Ϊ��
void Shift_down(int *arr, int n, int curpos) //n-�����С   curpos-��Ҫ������λ��
{
	//����
	int child = 2 * curpos + 1;
	while (child < n)
	{
		if (child + 1 < n&&arr[child + 1] < arr[child])
			child++;
		//���±Ƚ�
		if (arr[child] < arr[curpos])
		{
			int tmp = arr[child];
			arr[child] = arr[curpos];
			arr[curpos] = tmp;

			//�������±Ƚ�
			curpos = child;
			child = 2 * curpos + 1;
		}
		else
			break;
	}

}

void Creat_heap(int *arr, int n)
{
	for (int i = 0; i < (n - 2) / 2; i++)
	{
		Shift_down(arr, n, i);
	}
}

void test()
{
	int arr[] = { 100,20,3,6,89,12,15,36,25 };
	Creat_heap(arr,sizeof(arr)/sizeof(arr[0]));
}

int main()
{
	test();
	return 0;
}

