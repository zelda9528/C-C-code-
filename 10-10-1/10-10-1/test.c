#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int Add(int x, int y)
{
	return x + y;
}

int main()
{
	

	//����ָ�������

	//��һ��ָ������ָ�� - ��ź����ĵ�ַ

	//int (*pf)(int, int) = &Add;

	int(*pf)(int, int) = Add;

	int sum = (*pf)(2, 3);

	sum = pf(2, 3);

	printf("%d\n", sum);

	sum = Add(2, 3);

	printf("%d\n", sum);

	//int (*ps)(const char*) = &my_strlen;

	//printf("%p\n", &Add);

	//printf("%p\n", Add);

	//�������Ǻ����ĵ�ַ

	//&���������Ǻ����ĵ�ַ

	return 0;
}