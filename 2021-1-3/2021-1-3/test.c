#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//���µ����㷨
void Shift_down(int *arr, int n, int curpos)
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




int main()
{
	int arr[6] = { 10,5,3,8,7,6 };

	Shift_down(arr, sizeof(arr) / sizeof(arr[0]), 0);

	for (int i = 0; i < 6; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}