#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

using namespace std;

class A {
public:
	int _a;
};
//����̳У�virtual �̳з�ʽ ����
class B : virtual public A {
public:
	int _b;
};

class C : virtual public A {
public:
	int _c;
};

class D : public B, public C {
public:
	int _d;
};

void test()
{
	D d; 
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;

}

int main()
{
	test();
	return 0;
}