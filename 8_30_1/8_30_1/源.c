#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void main()
{
	int i, temp;
	int a[5], b[5];
	printf("�������������Ϊ��һ������:\n");
	for (i = 0; i <= 4; i++)
		scanf("%d", &a[i]);
	printf("�������������Ϊ�ڶ�������:\n");
	for (i = 0; i <= 4; i++)
		scanf("%d", &b[i]);
	for (i = 0; i <= 4; i++)
	{
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
	printf("����Ԫ��֮��ĵ�һ��������:\n");
	for (i = 0; i <= 4; i++)
		printf("%d ", a[i]);
	printf("\n");
	printf("����Ԫ��֮��ĵڶ���������:\n");
	for (i = 0; i <= 4; i++)
		printf("%d ", b[i]);
	printf("\n");
}