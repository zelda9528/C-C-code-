#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class A
{
public:
	int a;
	A(int x = 1 )
	{
		a = x;
		cout << "A()" << endl;
	}
};
class date {
public:
	//�޲ι��캯��
	date()
	{
		cout << "date()" << endl;
	}
	//���ι��캯��---Ҳ������ΪĬ�Ϲ��캯��
	date(int y=1, int m=1, int d=1)
	{
		year = y;
		month = m;
		day = d;
		cout << "date(int ,int ,int)" << endl;
	}
	//�������캯��--�βα���Ϊ������������
	//�������ʽ���忽�����캯�������������Զ�����
	date(const date&  a)
	{
		year = a.year;
		month = a.month;
		day = a.day;
		cout << "copy" << endl;
	}
private:
	int year;
	int month;
	int day;

	A a;

};

void test()
{

	date b(2021,2,3);	//�����вι��캯��
	date copy(b);
}

int main()
{
	test();
	return 0;
}