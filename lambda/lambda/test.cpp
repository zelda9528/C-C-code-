#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<functional>
#include<algorithm>
#include<vector>
using namespace std;

void test()
{
	//lambda���ʽ��[��׽�б�](�����б�)��mutable��ѡ��->����ֵ����{������}
	//��׽�б������������еı���
	int a = 10;
	int b = 20;
	[a, b] {return a + b; };
	
	//�����б������ں����ز����б�
	[a, b](int c) {return a + b + c; };

	//����ֵ�������ں�������ֵ
	[a, b](int c)->int {return a + b + c; };

	//�����壺�����ں����������ж��ָ��
	//mutable������׽�б��б����������޸�Ϊ��const��Ĭ����const
	[a, b](int c)mutable-> int {a = 10; b = 200; };

	//�����б�ͷ���ֵ����ʡ��
	[] {};	//�Ϸ�

	//����ֵһ�㲻��д�����������Զ��Ƶ�
	[a, b] {return a + b; };

	//���ʹ����mutable����ʹ�����б�Ϊ��Ҳ��Ҫ��ʽ��д����
	[a, b]()mutable{return a + b; };

	//����ֻ��lambda���ʽ�Ķ��壬�޷�ʹ�ã�Ҫ��ȡ��ֵ�����ʹ��

	auto f=[a, b](int c) {return a + b + c; };
	int e = f(10);

	//��������Ƚ϶���������·�ʽ�򵥵Ľ��н���
	//[=]����ֵ����ʽ��׽���в���
	auto f2 = [=]() {return a + b; };

	//[&]�������õ���ʽ��׽���в���
	auto f3 = [&]() {a = 1; b = 2; };
	f3(); 

	//[=,& x]��x��������ʽ��׽����������ֵ����ʽ��׽
	//[&,x]��x��ֵ����ʽ��׽����������������ʽ��׽
	//����Ĳ�׽��ʽ[=,x]

	//[this]����׽��Ա�����е�thisָ��
}

struct A {
	void fun(int a)
	{
		auto f=[this]() {return _a; };
	}
	int _a;
};
//void test()
//{
//	int array[]{ 4,5,6,3,2,1,7,8,9, };
//	sort(array, array + sizeof(array) / sizeof(array[0]));
//	sort(array, array + sizeof(array) / sizeof(array[0]),greater<int>());
//
//}
//
//struct A {
//public:
//	A(int age=1,int id=1,string name="")
//		:_age(age)
//		,_id(id)
//		,_name(name)
//	{}
//	int _age;
//	int _id;
//	string _name;
//	bool operator<(const A& a)
//	{
//		return _age < a._age;
//	}
//
//};
//
//struct Less {
//	bool operator()(const A& a, const A& b)
//	{
//		return a._id > b._id;
//	}
//};
//
//void test()
//{
//	vector<A> a = { {18,1,"zhangsan"},{17,2,"lisi"},{22,3,"wangwu"} };
//	sort(a.begin(), a.end());
//
//	sort(a.begin(), a.end(),Less());
//
//
//	//lambda���ʽ
//	sort(a.begin(), a.end(), 
//		[](const A&a, const A& b)
//	{return a._name > b._name; });
//
//
//}

int main()
{
	test();
	return 0;
} 