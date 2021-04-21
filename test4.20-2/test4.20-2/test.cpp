#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<array>
using namespace std;

//��ģ���ػ�
//ǰ�᣺�Ѿ���һ��ͨ�õ�ģ��
template<class T1,class T2>
struct D {
public:
	D(const T1& d1,const  T2& d2):d1_(d1),d2_(d2)
	{
		cout << "D(T1,T2)" << endl;
	}

	T1 d1_;
	T2 d2_;
};


//ȫ�ػ����������Ͷ��Ǿ�������
template<>
struct D<char,double> {
public:
	D(const char&d1, const double&d2) :d1_(d1), d2_(d2)
	{
		cout << "D(char,double)" << endl;
	}
	char d1_;
	double d2_;
};

//ƫ�ػ���2����ģ���������

template<class T1,class T2>
struct D<T1*,T2*> {
public:
	D(const T1& d1, const T2& d2) :d1_(d1), d2_(d2)
	{
		cout << "D(T1*,T2*)" << endl;
	}

	T1 d1_;
	T2 d2_;
};

//ƫ�ػ���1��ֻ�ػ���������
template<class T>
struct D< T, double> {
public:
	D(const T&d1, const double&d2) :d1_(d1), d2_(d2)
	{
		cout << "D(T,double)" << endl;
	}
	T d1_;
	double d2_;
};



void test()
{
	D<int, int>a(1, 2);
	D<char, double>b('c', 1.2);
	D<long, double>c(10000000, 1.2);
	D<int*, int*>d(1, 2);
}


int main()
{
	test();
	return 0;
}
