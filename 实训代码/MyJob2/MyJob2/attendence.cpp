#include "stdafx.h"
#include "attendence.h"

using namespace adosql;
attendence::attendence()
{
}


attendence::~attendence()
{
}
void attendence::CreatePage()
{
	cout << "*******************��ӭʹ�ÿ��ڹ�����*******************" << endl;
	cout << "+++++++++          1.������Ϣ����          +++++++++" << endl;
	cout << "+++++++++          2.������Ϣɾ��           +++++++++" << endl;
	cout << "+++++++++          3.������Ϣ��ѯ           +++++++++" << endl;
	cout << "+++++++++          4.������һ����           +++++++++" << endl;
	cout << "*****************************************************" << endl;
	int In = 0;
	cout << "������ָ�";
	cin >> In;
	switch (In)
	{
	case 1:Add(); break;
	case 2:Delete(); break;
	case 3:Query(); break;
	case 4:return; break;
	default:
		CreatePage();
		break;
	}
}
void attendence::Add()
{
	AdoCenter ATTENDENCEDB;
	cout << "������Ա��������";
	cin >> NAME;
	cout << "���������ڣ�";
	cin >> DATE;
	cout << "������Ա���ϰ��ʱ�䣺";
	cin >> START;
	cout << "������Ա���°��ʱ�䣺";
	cin >> END;
	cout << "������Ա���涨�ϰ�ʱ�䣺";
	cin >> NORSTART;
	cout << "������Ա���涨�°�ʱ�䣺";
	cin >> NOREND;
	string SQL = "INSERT INTO attendance VALUES ('"+ NAME +"','"+ START +"','"+ END +"','"+DATE+"','"+NORSTART+"','"+NOREND+"')";
	int Res = ATTENDENCEDB.executeSql(SQL);
	if (Res != -1)
	{
		cout << "�����ɹ�!!!" << endl;
	}
	else
	{
		cout << "����ʧ��!!!" << endl;
	}
	CreatePage();
	
}
void attendence::Delete()
{
	AdoCenter ATTENDENCEDB;
	cout << "������Ա��������";
	cin >> NAME;
	cout << "���������ڣ�";
	cin >> DATE;
	string SQL = "DELETE FROM attendance WHERE (NAME = '"+ NAME +"' and DATE='"+DATE+"')";
	int Res = ATTENDENCEDB.executeSql(SQL);
	if (Res != -1)
	{
		cout << "�����ɹ�!!!" << endl;
	}
	else
	{
		cout << "����ʧ��!!!" << endl;
	}
	CreatePage();
}

void attendence::Query()
{
	AdoCenter ATTENDENCEDB;
	cout << "*******************��ӭʹ�ÿ��ڹ�����*******************" << endl;
	cout << "+++++++++          1.��Ա��������ѯ          +++++++++" << endl;
	cout << "+++++++++          2.�����ڲ�ѯ              +++++++++" << endl;
	cout << "+++++++++          3.����ݲ�ѯ              +++++++++" << endl;
	cout << "+++++++++          4.������һ����            +++++++++" << endl;
	cout << "**********************************************************" << endl;
	int In = 0;
	cout << "������ָ�";
	cin >> In;
	switch (In)
	{
	case 1:
	{
		cout << "������Ա������(����)��";
		cin >> NAME;
		string SQL = "SELECT * FROM  attendance where ( NAME='" + NAME + "')";
		vector<string> Result;
		int res = ATTENDENCEDB.selectData(SQL, Result);
		if (Result.size() != 0 && res != -1)
		{
			cout << "����   �ϰ��ʱ��  �°��ʱ�� ���� �ϰ�涨ʱ�� �°�涨ʱ��" << endl;
			for (int i = 0; i < Result.size(); i++)
			{
				cout << Result[i] << endl;
			}
		}
		else
		{
			cout << "δ��ѯ���ü�¼!!!" << endl;
			CreatePage();
		}
		break;
	}
	case 2:
	{
		cout << "����������(2021-07-15)��";
		cin >> DATE;
		string SQL = "SELECT * FROM  attendance where ( DATE='" + DATE + "')";
		vector<string> Result;
		int res = ATTENDENCEDB.selectData(SQL, Result);
		if (Result.size() != 0 && res != -1)
		{
			cout << "����   �ϰ��ʱ��  �°��ʱ�� ���� �ϰ�涨ʱ�� �°�涨ʱ��" << endl;
			for (int i = 0; i < Result.size(); i++)
			{
				cout << Result[i] << endl;
			}
		}
		else
		{
			cout << "δ��ѯ���ü�¼!!!" << endl;
			CreatePage();
		}
		break;
	}
	case 3:
	{
		cout << "���������(2021)��";
		cin >> DATE;
		string SQL = "SELECT * FROM attendance WHERE DATE BETWEEN '"+DATE+"-01-01' AND '"+DATE+"-12-31'";
		vector<string> Result;
		int res = ATTENDENCEDB.selectData(SQL, Result);
		if (Result.size() != 0 && res != -1)
		{
			cout << "����   �ϰ��ʱ��  �°��ʱ�� ���� �ϰ�涨ʱ�� �°�涨ʱ��" << endl;
			for (int i = 0; i < Result.size(); i++)
			{
				cout << Result[i] << endl;
			}
		}
		else
		{
			cout << "δ��ѯ���ü�¼!!!" << endl;
			CreatePage();
		}
		break;
	}
	default:
		CreatePage();
		break;
	}
	CreatePage();

}
