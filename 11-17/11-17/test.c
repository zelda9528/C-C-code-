#define _CRT_SECURE_NO_WARNINGS 1

#define ZHANGSAN 0
#include<stdio.h>

int main()
{
	#if defined(ZHANGSAN)
		printf("����\n");
	#endif

	#if !defined(ZHANGSAN)
		printf("����\n");
	#endif

	#ifdef ZHANGSAN
		printf("zhangsan\n");
	#endif

	#ifndef ZHANGSAN
		printf("zhangsan\n");
	#endif

		return 0;
}
