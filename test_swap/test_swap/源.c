#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void swap(int *pa, int *pb)
{
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	printf("����ǰ��a=%d b=%d\n", a, b);
	swap(&a, &b);
	printf("������a=%d b=%d\n", a, b);
	return 0;
}