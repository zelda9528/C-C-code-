#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	int a, b, c;
	for (a = 1; a <= 20; a++)
		for (b = 1; b <= 33; b++)
		{
			c = 100 - a - b;
			if (a * 5 + b * 3 + c / 3 == 100 && a + b + c == 100 && c % 3 == 0)
				printf("����%dֻ  ĸ��%dֻ  С��%dֻ\n", a, b, c);
		}
	return 0;
}