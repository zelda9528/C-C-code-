#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include <assert.h>
void search(int a[], int num)
{
	assert(a);
	assert(num > 0);
	int *x = (int *)malloc(sizeof(int *));
	int *y = (int *)malloc(sizeof(int *));
	*x = 0;
	*y = 0;
	//ȫ�����а�λ�룬������ͬ���ְ�λ��Ϊ�㲻ͬΪһ����˽��һ����Ϊ�㣬��32������λ��������һλΪ1��
	int sum = a[0];
	for (int i = 0; i < num; i++)
	{
		sum ^= a[i];
	}
	//�ҵ����λ��һ�γ���1��λ�ã���Ϊpos����Ϊ��ʱ��1һ���ǲ�ͬ����������Ӧλ���ϵ�1��0���õ��ġ�
	int pos = 1;
	{
		while (sum & 1)
		{
			sum = sum >> 1;
			pos = pos << 1;
		}
	}
	//����posλ���ϵ�01ֵ��ͬ�������黮��Ϊ�������飬��������򣬵ó�ÿ���������һ�ε�����
	for (int i = 0; i < num; i++)
	{
		if (a[i] & pos)
		{
			*x ^= a[i];
		}
		else
		{
			*y ^= a[i];
		}
	}
	printf("%d %d", *x, *y);
}
int main(void)

{

	int a[] = { 1, 2, 3, 7, 4, 5, 1, 2, 3, 7 };
	int num = sizeof(a) / sizeof(a[0]);
	search(a, num);

}