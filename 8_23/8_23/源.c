#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int x;
	char a[16];

	printf("�������ı���ɫ����(1-��,2-��,4-��,6-��,7-��):");
	scanf("%d", &x);

	sprintf(a, "color 0%d", x);
	system(a);
	printf("Hello world!\n");

	return 0;
}