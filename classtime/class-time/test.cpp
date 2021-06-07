#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Date {
public:
	Date(int y = 1, int m = 1,int d=1)
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
			_y= y;
			_m = m;
			_d = d;
		}

	}
	int getday(int y, int m)
	{
		static int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		int day= days[m];
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

	//Date + int
	//�������֮��Ľ�������������ı�
	Date operator+(int day)
	{
		Date copy = *this;
		return copy += day;
	}

	//++Date
	Date& operator++()
	{
		return *this += 1;
	}

	//Date++
	Date operator++(int)
	{
		Date copy(*this);
		*this += 1;

		return copy;
	}

	//Date -= int 
	Date& operator-=(int day)
	{
		//�����������
		_d -= day;

		//�ж��Ƿ����
		while (_d < 0 )
		{
			//���ϵ�������
			_d += getday(_y, _m-1);

			//�·���λ
			--_m;

			//�·��Ƿ����
			if (_m < 0 )
			{
				//�����λ
				--_y;

				//�·ݸ���Ϊ12��
				_m = 12;
			}

		}
		//�������֮��Ľ��
		return *this;
	}

	// ����--
	Date operator--(int)
	{
		Date copy(*this);
		*this -= 1;
		return copy;
	}

	// ǰ��--
	Date& operator--()
	{
		*this -= 1;
		return *this;
	}

	// >���������
	bool operator>(const Date& d)
	{
		if (_y > d._y)
		{
			return true;
		}
		else if (_y == d._y)
		{
			if (_m > d._m)
			{
				return true;
			}
			else if (_m == d._m)
			{
				if (_d > d._d)
				{
					return true;
				}
			}
		}
		return false;
	}

	// ==���������
	bool operator==(const Date& d)
	{
		return _y == d._y
			&& _m == d._m
			&& _d == d._d;
	}

	// ���渴������������ʵ��
	// >=���������
	inline bool operator >= (const Date& d)
	{
		return *this > d || *this == d;
	}

	// <���������
	bool operator < (const Date& d)
	{
		return !(*this >= d);
	}

	// <=���������
	bool operator <= (const Date& d)
	{
		return !(*this > d);
	}

	// !=���������
	bool operator != (const Date& d)
	{
		return !(*this == d);
	}

	// d1 - d2
	// ����-���� ��������
	int operator-(const Date& d)
	{
		int flag = 1;
		Date max = *this;
		Date min = d;
		if (*this < d)
		{
			max = d;
			min = *this;
			flag = -1;
		}
		int day = 0;
		while (min < max)
		{
			++(min);
			++day;
		}
		return day * flag;
	}

private:
	int _y;
	int _m;
	int _d;

};

void test()
{
	Date d1(2021,2,4);
	Date d2(2021, 2, 4);
	Date d3(2021, 2, 4);
	Date d4(2021, 2, 4);
	Date d5(2021, 2, 4);


}

int main()
{
	test();
	return 0;
}