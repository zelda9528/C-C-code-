#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class A {
public:
	A() {}
	virtual void fun1() {}
	virtual void fun2() {}
	void fun3() {}
	int _a;
 };

class B :public A {
public:
	void fun1(){}
	int _b;
};
int main()
{
	A a;
	B b;
	cout << sizeof(a) << endl;
	return 0;
}




//class A{};
//
//class B :public A {};
//
//
//class Person {
//public:
//	virtual A* RedPapper()
//	{
//		cout << "100��" << endl;
//		return new A;
//	}
//};
//
//class Student :public Person {
//public:
//	//Э�䣺����ֵΪ���м̳й�ϵ��ָ�������
//	B* RedPapper()
//	{
//		cout << "1ë" << endl;
//		return new B;
//	}
//};
//
//void test()
//{
//	Person p;
//	Person* rp=&p;
//	rp->RedPapper();
//
//	rp = (Person*)new Student;
//	rp->RedPapper();
//}
//
//int main()
//{
//	test();
//	return 0;
//}



//class Person {
//public:
//	virtual void BuyTicket()
//	{
//		cout << "ȫƱ" << endl;
//	}
//	virtual Person* RedPapper()
//	{
//		cout << "100��" << endl;
//			return new Person;
//	}
//};
//
//class Student :public Person {
//public:
//	//��д���������������б�����ֵ�븸���麯����ȫ��ͬ
//	void BuyTicket()
//	{
//		cout << "��Ʊ" << endl;
//	}
//	//Э�䣺����ֵΪ���м̳й�ϵ��ָ�������
//	Student* RedPapper()
//	{
//		cout << "1ë" << endl;
//		return new Student;
//	}
//};
//
//
//void test()
//{
//	Person p;
//	Person* p1 = &p;
//	Person& p2 = p;
//	//p.BuyTicket();	//�ö����������麯��ʱ�����������̬
//
//	p1->BuyTicket();	
//	p2.BuyTicket();
//	p1->RedPapper();
//	p2.RedPapper();
//
//	Student s;
//	p1 = &s;
//	Person& p3 = s;
//	p1->BuyTicket();
//	p3.BuyTicket();
//
//	p1->RedPapper();
//	p3.RedPapper();
//
//}
//
//int main()
//{
//	test();
//	return 0;
//}
