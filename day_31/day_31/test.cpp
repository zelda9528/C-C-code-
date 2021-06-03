#define _CRT_SECURE_NO_WARNINGS 1
// write your code here cpp

#include<iostream>
#include<cstdio>
using namespace std;

bool isLeapYear(int y)
{
	return ((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0);
}

//�·�
int DAYS[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

//��� y  m  d  ��һ����˶�����
int nDays(int y, int m, int d)
{
	int n = d;

	for (int i = 0; i < m - 1; i++)
	{
		n += DAYS[i];
	}
	if (m > 2 && isLeapYear(y))
	{
		n += 1;
	}
	return n;
}

//���� y m d  ����ӻ�׼���ڵ����������ڹ��˶�����%7
int diff(int y, int m, int d)
{
	return (y - 1) + (y - 1) / 4 - (y - 1) / 100 + (y - 1) / 400 + nDays(y, m, d);
}

//���� y  m  d �����ܼ�
int week(int y, int m, int d)
{
	int w = diff(y, m, d)%7;
	if (w == 0)
		w = 7;
	return w;
}

//��֪����1��������w�������n������e�Ǽ���
int m1(int w, int n, int e)
{
	return 1 + (n - 1) * 7 + (7 - w + e) % 7;
}

//��֪6��1��������w������5�µ����һ������1
int m2(int w)
{
	int d = (w == 1 ? 7 : w - 1);
	return 32 - d;
}

int main()
{
	int y;
	while (cin >> y)
	{
		/*
		���й��Ľ��ղ�ͬ�������Ľڼ���ͨ����ѡ��ĳ���µĵڼ������ڼ�������ʽ�����ÿһ��ķż����ڶ�����ͬ������������£�
		* 1��1�գ�Ԫ��
		* 1�µĵ���������һ������·�¡��������
		* 2�µĵ���������һ����ͳ��
		* 5�µ����һ������һ��������ʿ������
		* 7��4�գ���������
		* 9�µĵ�һ������һ���Ͷ���
		* 11�µĵ��ĸ������ģ��ж���
		* 12��25�գ�ʥ����
		���ڸ���һ����ݣ������æ���ɵ�����յ����ڡ�
		*/
		printf("%d-01-01\n", y);
		int w;
		w = week(y, 1, 1);
		printf("%d-01-%02d\n", y, m1(w, 3, 1));
		w = week(y, 2, 1);
		printf("%d-02-%02d\n", y, m1(w, 3, 1));

		w = week(y, 6, 1);
		printf("%d-05-%d\n", y, m2(w));


		printf("%d-07-04\n", y);

		w = week(y, 9, 1);
		printf("%d-09-%02d\n", y, m1(w, 1, 1));

		w = week(y, 11, 1);
		printf("%d-11-%02d\n", y, m1(w, 4, 4));

		printf("%d-12-25\n\n", y);
	}
	return 0;
}

