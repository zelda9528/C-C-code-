#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
int main()
{
	int i;
	int &j = i;
	i = 30;
	cout << "i=" << i << ' ' << "j=" << j << endl;
	j = 80;
	cout << "i=" << i << ' ' << "j=" << j << endl;
	cout << "����i�ĵ�ַ�ǣ�" << &i << endl;
	cout << "����j�ĵ�ַ��: " << &j << endl;
	return 0;
}
