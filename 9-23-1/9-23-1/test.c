#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	printf("������һ��1~9֮���������\n");
	int a;
	scanf("%d", &a);
	int Sn = 0;
	int i;
	int temp = 0;
	for (i = 0; i < 5; i++) {
		Sn = Sn + a * pow(10, i);    //ȡ��ÿһ����
		temp = temp + Sn;        //���Ѿ�ȡ�������ĺ������
	}
	printf("%d\n", temp);
	return 0;
}