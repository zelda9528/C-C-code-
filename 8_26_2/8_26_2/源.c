#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//�ݹ鷽����׳�
int Fac(int n)
{
	if (n <= 1)
		return 1;
	else
		return n*Fac(n - 1);
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = Fac(n);
	printf("%d\n", ret);
	return 0;
}





////�ǵݹ鷽����׳�
//int main()
//{
//	int i = 1;
//	int n = 0;
//	int j = 0;
//	scanf("%d", &n);
//	for (j = 1; j <= n; j++)
//	{
//		i = i * j;
//	}
//	printf("%d\n", i);
//	return 0;
//}