#include "stdafx.h"
#include "attendquery.h"
using namespace adosql;

attendquery::attendquery()
{
}


attendquery::~attendquery()
{
}
void attendquery::CreatePage()
{
	AdoCenter QUERYDB;
	cout << "*******************��ӭʹ�ÿ��ڻ��ܲ�ѯ����*******************" << endl;
	cout << "������Ա�����ƣ�";
	cin >> NAME;
	cout << "����������(2021-07)��";
	cin >> DATE;
	DATE = DATE + "-04";
	string SQL = "SELECT * FROM attendance WHERE DATE BETWEEN DATE_ADD('" + DATE + "',interval -day('"+ DATE +"')+1 day) AND last_day(curdate()) AND `NAME`='"+NAME+"'; ";
	vector<string> Result;
	int res = QUERYDB.selectData(SQL, Result);
	if (Result.size() != 0 && res != -1)
	{
		for (int i = 0; i < Result.size(); i++)
		{
			cout << Result[i] << endl;
		}
		cout << NAME + "���¹�������Ϊ��" + to_string(Result.size())<< endl;
		SQL = "SELECT * FROM attendance WHERE DATE BETWEEN DATE_ADD('" + DATE + "',interval -day('" + DATE + "')+1 day) AND last_day(curdate()) AND SUBTIME(NORSTART,`START`)<0 AND `NAME`='"+NAME+"'; ";
		Result.clear();
		QUERYDB.selectData(SQL, Result);
		cout << NAME+"���³ٵ�����Ϊ��" + to_string(Result.size()) << endl;
		SQL = "SELECT * FROM attendance WHERE DATE BETWEEN DATE_ADD('" + DATE + "',interval -day('" + DATE + "')+1 day) AND last_day(curdate()) AND SUBTIME(NOREND,`END`)>0 AND `NAME`='" + NAME + "'; ";
		Result.clear();
		QUERYDB.selectData(SQL, Result);
		cout << NAME + "������������Ϊ��" + to_string(Result.size()) << endl;
	}
	else
	{
		cout << "δ��ѯ���ü�¼!!!" << endl;
		return ;
	}

}
