#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int check_sys()
{
	union Un
	{
		int i;
		char c;
	}u;
	u.i = 1;
	//����0����ʾ���
	//����1����ʾС��
	return u.c;
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
