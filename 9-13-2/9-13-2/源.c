#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a = 15;//00000000000000000000000000001111
	int b = 8 ;//00000000000000000000000000001000
	int count = 0;
	for (int i = 0; i < 32; i++)
	{
		if (((a >> i) & 1) != ((b >> i) & 1))
			count++;
	}
	printf("��%d��������λ��ͬ\n", count);
	return 0;
}