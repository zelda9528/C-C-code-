#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

using namespace std;


class A{
public:
	virtual void fun()	//�麯��
	{}
};
class B:public A{
	void fun()	//��д�����麯��
	{}
};

int main()
{
	int a=1;
	double f=1.2;
	int *p = &a;


	//1.static_cast:֧�����е���ʽ����ת����
	//���⣺����֧����ָ��������õ�����ָ��������õ�ǿ������ת��
	//     ��֧��������ǿ������ת����

	//ǿ������ת��
	a = (int)p;

	//��֧�֣�a = static_cast<int>(pa);

	a = static_cast<int>(f);

	A* pa = new A;
	B* pb = (B*)pa;
	B* pb1 = static_cast<B*>(pb);



	//2. reinterpret_cast��֧��ǿ������ת��
	a = reinterpret_cast<int>(pa);

	//3.const_cast:ȥ��������const����
	volatile const int m = 10;
	cout << "m:" << m << endl;

	//��������ָͨ��ȡconst���ݵĵ�ַ��int *pm = &m;
	int *pm = const_cast<int*>(&m);
	
	*pm = 100;
	cout << "m:" << m << endl;

	//4.dynamic_cast:ֻ�����ڶ�̬�����£����������/ָ��������ת��
	A* paa = new A;
	B* pbb = dynamic_cast<B*>(pa);

	return 0;
}