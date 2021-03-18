#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Date {
public:

	friend ostream& operator<<(ostream& _cout, const Date& d);


	Date(int y = 1, int m = 1, int d = 1)
	{
		//�ж������Ƿ���Ч
		if (y <= 0 || m <= 0 || m > 12 || d <= 0 || d > getday(y, m))
		{
			//������Ч
			y = 1;
			m = 1;
			d = 1;
			cout << "������Ч,��ΪĬ��ֵ��1-1-1" << endl;
		}
		else
		{
			_y = y;
			_m = m;
			_d = d;
		}

	}


	int getday(int y, int m)
	{
		static int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		int day = days[m];
		//���Ϊ���£�����Ϊ���꣬�޸�����
		if (m == 2 && (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0)))
			day += 1;
		return day;
	}


	//���ڵ�����
	//Date += int
	//��������ı�Ϊ��Ӻ�Ľ��
	//2021��2.4 + 90 �� 2021.2.94 -28 ---> 2021.3.66 - 31 ---> 2021.4.35 - 30 ---> 2021.5.5
	Date& operator+=(int day)
	{
		//�����������
		_d += day;
		//�ж��Ƿ����
		while (_d > getday(_y, _m))
		{
			//��ȥ��������
			_d -= getday(_y, _m);
			//�·ݽ�λ
			++_m;
			//�·��Ƿ����
			if (_m == 13)
			{
				//��ݽ�λ
				++_y;
				//�·ݸ���Ϊһ��
				_m = 1;
			}
		}
		//�������֮��Ľ��
		return *this;
	}

	

private:
	int _y;
	int _m;
	int _d;


};

ostream& operator<<(ostream& _cout, const Date& d)
{
	//_cout << d._y << "-" << d._m << "-" << d._d;
	printf("%04d-",d._y);
	printf("%02d-", d._m);
	printf("%02d", d._d);

	return _cout;
}

int main()
{
	int i = 0;
	cin >> i;
	int y, m, d,num;
	while (i-- > 0)
	{
		cin >> y >> m >> d >> num;
		Date a(y, m, d);
		a += num;
		cout << a << endl;
	}

	return 0;
}