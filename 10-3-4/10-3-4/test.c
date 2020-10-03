#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void swapArgs(int * a, int * b) //��������
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void diveRank(int * p, int n)
{
	if (n >= 5) //��ʱ��nҲ����������ѭ�������ġ�
	{
		if ((p[1] == 2) + (p[0] == 3) == 1 && //B�ڶ����ҵ���
			(p[1] == 2) + (p[4] == 4) == 1 && //�ҵڶ���E����
			(p[2] == 1) + (p[3] == 2) == 1 && //�ҵ�һ��D�ڶ�
			(p[2] == 5) + (p[3] == 3) == 1 && //C����ҵ���
			(p[4] == 4) + (p[0] == 1) == 1)   //�ҵ��ģ�A��һ
			//���ڴ�ʱ��ִ�е�ȫ���У����Բ���Ҳʡ�ˡ�
		{
			for (int i = 0; i < 5; i++)
			{
				printf("%d ", p[i]);
			}
			putchar('\n');
		}
		return;
	}

	int i;
	for (i = n; i < 5; i++) //����ݹ鷽ʽ������˶�1~5��ȫ���У������ǴӺ���ǰ��ͣ��ִ�н��������Բο��Ľ�����ԭ���룬������ݹ����д�س�ѭ���󣬿��Ը��õ���⡣
	{
		swapArgs(p + i, p + n);
		diveRank(p, n + 1);
		swapArgs(p + i, p + n);
	}
}

int main()
{
	int p[5] = { 1, 2, 3, 4, 5 }; //��Ȼ������ȫ���У����Գ�ֵ������á�

	diveRank(p, 0);

	return 0;
}