#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>


char* my_strcat(char* dest, const char* src)
{
	char* ret = dest;
	assert(dest != NULL);
	assert(src != NULL);

	//1. ��Ŀ�ĵؿռ��'\0'
	while (*dest)
	{
		dest++;
	}
	//2. ��������
	while (*dest++ = *src++)
	{
		;
	}

	return ret;
}

int main()
{
	char arr1[20] = "hello ";

	printf("%s\n", my_strcat(arr1, "world"));
	return 0;
}