#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class A {
public:
	A(int a) :_a(1)
	{
		cout << "A()" << endl;
	}
private:
	int _a;
};

int main()
{
	A obj1(1);
	A obj2 = obj1;
	A obj3 = 20;	//������20��ʼ����Ķ��󣬷������ι��캯������ʽ����ת�� 
					//����������������20��ʼ��һ����ʱ����������Ȼ���ø���ʱ�����obj3���и�ֵ	
	return 0;
}

