#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<set>
#include<list>
#include<map>
using namespace std;
////C++11���ݳ�ʼ����ʽ
//
//struct A {
//	 int _a;
//	/*explicit*/ A(int a):_a(a)
//	{}
//
//	A(int a, int b, int c) :_a(a)
//	{}
//
//};
//
//template<class T>
//class Vector{
//private:
//	T _a;
//	size_t _capacity;
//	size_t _size;
//
//public:
//	Vector(int a = 1):_a(a),_capacity(10),_size(1)
//	{}
//	Vector(init):_a
//
//};
//
//
//
//void test()
//{
//	A a1(100);
//	A a4 = 100;	//���ι������ʽ����ת��
//	//C++11��֧���������� �Զ������͵��б��ʼ����ʽ
//	A a2{ 100 };
//	A a3 = { 100 };
//	A a5 = { 1,2,3 };
//
//	vector<int> v1(1);
//	vector<int> v2(10,0);
//	vector<int> v3 = { 1,2,3,4,5 };
//	vector<int> v4{ 1,2,3,4,5,6 };
//
//	set<int> s{ 1,2,3,4,5,1,2,3,4,5 };
//	map<int, int> m{ {1,100},{2,200} ,{3,300} };
//
//	pair<int, int> p = { 1,3 };
//
//	//�Զ��������������Ҫʹ���б��ʼ��
//	//��Ҫ����һ�����캯��������Ϊinitializer_list ���󣨳�ʼ���б�
//
//	int arr[]{ 1,2,2,2 };
//
//}
//
//
//class A {
//public:
//	A(int a)
//	{}
//
//	//default���ñ�������ʽ������һ��Ĭ�ϵĹ��캯��
//	A() = default;
//
//	A(const A&) = default;
//
//	A& operator=(const A&) = default;
//};
//
//class B {
//public:
//	B(){}
//	//��Ա�������������Ϊdelete��������ʾ���������ٱ�ʹ��
//	//���磺��ֹ��������ֹ��ֵ
//	B(const B&) = delete;
//
//	B& operator=(const B&) = delete;
//};
//
//void test2()
//{
//	B b;
//	//B b2 = b;
//	//B b2(b);
//}
//
//int main()
//{
//	test();
//	return 0;
//}


//C++11��ֵ���á���ֵ����
int fun(int a) { return a; }

void test()
{
	//��ֵ���ã�����������ֵҲ����������ֵ--������ֵҪ��const�ؼ���
	int a = 10;
	int &ra = a;
	const int &ri = 10;
	const int &ri2 = fun(a);


	//��ֵ����&&��ֻ��������ֵ
	int &&rri = 10;
	int &&rri2 = fun(a);
}

int main()
{
	test();
	return 0;
}