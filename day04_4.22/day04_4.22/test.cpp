#define _CRT_SECURE_NO_WARNINGS 1


#include <iostream>
#include <string>
using namespace std;

/*ʮ����ת�������ƣ���Ȩȡ�൹�Ŷ�
 *���ϳ�Nֱ��MΪ0��ȡ������Ӧ���浽s���������s�������
 *���Ǽ��������
 *	��������תΪ����������ٲ�'-'��
 *	��������9��ֱ�Ӵ���table����Ӧ���棬��10��ӦΪ��10��Ԫ��A
*/
int main()
{
	int M, N;
	bool flag = false;//�����ж��Ƿ�Ϊ�����Խ��м�'-'����
	string s, table = "0123456789ABCDEF";
	cin >> M >> N;
	if (M < 0)
	{
		M = 0 - M;
		flag = true;
	}
	while (M)
	{
		s += table[M%N];
		M /= N;
	}
	if (flag)
		s += '-';
	reverse(s.begin(), s.end());
	cout << s << endl;
	return 0;
}






//�����ǹ�
//
//int main()
//{
//	int a, b, c, d;
//	cin >> a >> b >> c >> d;
//	int A = (a + c) / 2;
//	int C = (d - b) / 2;
//	int B1 = (c - a) / 2;
//	int B2 = (b + d) / 2;
//	if (B1 != B2)
//		cout << "No";
//	else
//		cout << A << " " << B1 << " " << C;
//	return 0;
//}


//
//void test()
//{
//	int a[5] = {1,3,5,7,9};
//	int *p = (int *)(&a + 1);
//	printf("%d %d", *(a + 1), *(p - 1));
//}
//
//int main()
//{
//	test();
//	return 0;
//}





//FIB:   1   1    2    3    5    8    13    21
//fib:  8=7+6;							cnt=1
//		7 = 6 + 5;   6=5+4;				cnt=3
//			6=5+4;  5=4+3;  5=4+3; 4= 3+2;	cnt=4
//			5=4+3; 4=3+2;  4=3+2; 3=2+1; 4=3+2; 3=2+1; 3=2+1; 2=1+0;  cnt=12;
//          4=3+2; 3=2+1;   3=2+1  
//int cnt = 0;
//
//int test(int n)
//{
//	cnt++;
//	if (n == 0)
//		return 1;
//	else if (n == 1)
//		return 2;
//	else
//		return test(n - 1) + test(n - 2);
//}
//
//int main()
//{
//	test(8);
//	cout << cnt << " ";
//	return 0;
//}