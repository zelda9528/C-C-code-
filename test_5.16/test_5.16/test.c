#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
//
//int check_sys()
//{
//	union Un
//	{
//		int i;
//		char c;
//	}u;
//	printf("%p ", &u.c);
//	printf("%p ", &u.i);
//
//	u.i = 1;
//	//����0����ʾ���
//	//����1����ʾС��
//	return u.c;
//}


int check_sys()
{
	int a = 1;
	char b = a;

	if (b == 0)
		return 0;
	else if (b == 1)
		return 1;
	else
		return -1;
}

int main()
{
	int ret = check_sys();
	if (ret == 1)
	{
		printf("С��\n");
	}
	else
	{
		printf("���\n");
	}
	return 0;
}