#define _CRT_SECURE_NO_WARNINGS 1


//��������Ӵ�
#include<iostream>
#include<string>
#include<vector>

using namespace std;

string getComSubstr(string& s1, string& s2)
{
	//��s1����Ϊ����ַ���
	if (s1.size() > s2.size())
		swap(s1, s2);

	int start = 1;    //�����Ӵ���ʼλ��
	int max_length = 0;//�����Ӵ���󳤶�

	int len1 = s1.size();
	int len2 = s2.size();
	vector<vector<int>> MSC(len1 + 1, vector<int>(len2 + 1, 0));
	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			if (s2[j - 1] == s1[i - 1])
				MSC[i][j] = MSC[i - 1][j - 1] + 1;

			if (MSC[i][j] > max_length)
			{
				max_length = MSC[i][j];
				start = i - max_length;
			}

		}
	}

	return s1.substr(start, max_length);
}

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		string substr = getComSubstr(s1, s2);
		cout << substr << endl;
	}
	return 0;
}

//��ˮƿ����
//#include<iostream>
//
//using namespace std;
//
//int calcNum(int n)
//{
//	int sum = 0;//���ܶһ�����ˮ����
//	while (n > 1)
//	{
//		int res = n / 3;//�ɶһ�����ˮ����
//		int left = n % 3;//�һ�������µĿ�ƿ����
//
//		sum += res;
//		n = left + res;
//		if (n == 2)
//		{
//			sum++;
//			break;
//		}
//	}
//	return sum;
//}
//
//int main()
//{
//	int n, res;
//	while (cin >> n)
//	{
//		if (n == 0)
//			break;
//		res = calcNum(n);
//		cout << res << endl;
//	}
//
//	return 0;
//}