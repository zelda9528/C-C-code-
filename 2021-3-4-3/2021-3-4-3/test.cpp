#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class A {
public:
	A(int a = 1) :_a()
	{
		
	}
	void print()
	{
		cout << this->_a << endl;
	}
private:
	int _a=0;		//C++11�ĳ�Ա��ʼ���·���
					//�˴���ȱʡֵֻ����������ֵ����ʱ�Ż�ʹ��
					//�����ڷ�static��Ա
};

int main()
{
	A x;
	x.print();
	return 0;
}