#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

void check_sys1()
{
	int a = 1;
	char* b = (char*)&a;
	if (*b == 1)
		cout << "С��" << endl;
	if (*b == 0)
		cout << "���" << endl;
}
void check_sys2()
{
	//�������͵��������ݹ���һ���ڴ棬�ڴ��С���������������;���
	union UN {
		int a;
		char b;
	}u;
	u.a = 1;
	if(u.b==1)
		cout << "С��" << endl;
	if(u.b==0)
		cout << "���" << endl;
}
int main()
{
	check_sys1();
	check_sys2();
	return 0;
}