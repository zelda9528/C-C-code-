#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define P 1 //��ˮ�ĵ���
#define N 2 //��һƿ��ˮ����Ŀ�ƿ����

//SodaConvert���������ÿ�ƿ��������ˮ����
int SodaConvert(int x)
{
	int ret = x / N;//��ƿ�һ�����ˮ����
	int empty = x / N + x % N;//�һ�����ˮ��ʣ�µĿ�ƿ����֮��
	if (empty > 1)
		return ret + SodaConvert(empty);
	else
		return ret;
}
int main()
{
	int p = 0;
	int n = 0;
	printf("�������");
	scanf("%d", &p);
	n = p / P;
	int bottle = n + SodaConvert(n);//���պȵ�����ˮ����
	printf("%dƿ\n", bottle);
	return 0;
}