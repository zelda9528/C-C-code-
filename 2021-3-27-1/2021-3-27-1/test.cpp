#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
int ans;
//ԭ�����ܺ���Ϣ 
int main()
{
	int x = 10000;
	while (x)
	{
		//����һ�����ȫ�̣� �Ǿ��� 
		if (x - 600 >= 0)
		{
			ans = ans + 60 * 2;
			x = x - 600 + 300;
		}
		else
		{//������ܲ���ȫ�̣��Ǿ��ܶ�������� ����������ĺ����Ӷ��Ǿ��ȱ仯 
			ans = ans + 0.1*x;
			x = 0;
		}
	}
	cout << ans << endl;
	return 0;
}
