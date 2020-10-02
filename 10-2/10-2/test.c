/*
˼·��
1. ���������±�left��right��left�����������ʼλ�ã�right�������������һ��Ԫ�ص�λ��
2. ѭ������һ�²���
 a. ���left��right��ʾ������[left, right]��Ч������b���������ѭ��
 b. left��ǰ�����ң��ҵ�һ��ż����ֹͣ
 c. right�Ӻ���ǰ�ң��ҵ�һ��������ֹͣ
 d. ���left��right���ҵ��˶�Ӧ�����ݣ��򽻻�������a��
*/
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void swap_arr(int arr[], int sz)
{
	int left = 0;
	int right = sz - 1;
	int tmp = 0;
	while (left < right)
	{
		while ((left < right) && (arr[left] % 2 == 0))
		{
			left++;
		}
		while ((left < right) && (arr[right] % 2 == 1))
		{
			right--;
		}
		if (left < right)
		{
			tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}
	}
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	swap_arr(arr, sz);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}