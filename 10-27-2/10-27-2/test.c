#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define ROW 3  
#define COL 3

int Find(int a[ROW][COL], int x)
{
	int i = 0;      //��ʼ��i��j
	int j = COL - 1;
	while (j >= 0 && i < COL)
	{
		if (a[i][j] < x) //���Ҵ������
		{
			i++;
		}
		else if (a[i][j] > x) //����С������
		{
			j--;
		}
		else
		{
			return 1;
		}
	}
	return 0;

}
int  main()
{
	int a[3][3] = { 1,2,3,4,5,6,7,8,9 };
	printf("������Ҫ���ҵ�����");
	int x = 0;
	scanf("%d", &x);
	if (Find(a, x))
	{
		printf("�ҵ���\n");
	}
	else
	{
		printf("û�ҵ�\n");
	}
	return 0;
}

