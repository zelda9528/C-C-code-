#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
int main()
{
	int i, j, k;
	int n;
	printf("������һ������:");
	scanf("%d", &n);//���ε�����
	n = n / 2 + 1;
	//��ӡ�ϰ��������
	for (i = 1; i < n; i++)//��������,�ϰ벿�ֱ��°벿����һ��
	{
		for (j = i; j < n; j++)
		{
			printf(" ");
		}
		for (k = 1; k <= 2 * i - 1; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	//��ӡ�°벿�ֵĵ�������
	for (i = 1; i <= n; i++)//��������,�°벿�ֱ��ϰ벿�ֶ�һ��
	{
		for (j = 1; j < i; j++)
		{
			printf(" ");
		}
		for (k = n * 2 - 1; k >= 2 * i - 1; k--)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}