#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
size_t my_strlen1(const char* string)
{
	//count ����¼�ַ����ĳ���
	size_t count = 0;
	//�жϲ���Ϊ�յĻ�����һ�������ֵ
	if (string == NULL)
	{
		return -1;
	}
	//�������飬ָ�������Ҽ���
	while (*string != '\0')
	{
		count++;
		string++;
	}
	return count;
}
int main()
{
	char string[] = "hello world";
	printf("%lu\n", my_strlen1(string));
	return 0;
}