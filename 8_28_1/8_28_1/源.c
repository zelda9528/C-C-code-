#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	float h, s;
	h = s = 100;
	h = h / 2; //��һ�η����߶�
	for (int i = 2; i <= 10; i++)
	{
		s = s + 2 * h;
		h = h / 2;
	}
	printf("��10�����ʱ��������%f�ף���10�η�����%f��\n", s, h);
	return 0;
}
   
