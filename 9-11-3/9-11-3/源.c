#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int count_one(int n) 
{
	int count = 0;
	while (n)
	{
		n = n & (n - 1);
		count++;
	}
	return count;
}
int main()
{
	int a = 7;
	int ret =	count_one(a);
	printf("��������һ����%d��1", ret);
	return 0;
}