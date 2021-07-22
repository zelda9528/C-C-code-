#include "stdafx.h"
#include "department.h"

using namespace adosql;
department::department()
{
}


department::~department()
{
}
void department::CreatePage()
{
	cout << "*******************��ӭʹ�ò��Ź�����*******************" << endl;
	cout << "+++++++++          1.������Ϣ����           +++++++++" << endl;
	cout << "+++++++++          2.������Ϣ�޸�           +++++++++" << endl;
	cout << "+++++++++          3.������Ϣ��ѯ           +++++++++" << endl;
	cout << "+++++++++          4.������һ����           +++++++++" << endl;
	cout << "*****************************************************" << endl;
	int In = 0;
	cout << "������ָ�";
	cin >> In;
	switch (In)
	{
	case 1:Add(); break;
	case 2:Modify(); break;
	case 3:Query(); break;
	case 4:return; break;
	default:
		CreatePage();
		break;
	}
}
void department::Add()
{
	AdoCenter DEPARTDB;
	cout << "�����벿�����ƣ�";
	cin >> NAME;
	cout << "�����벿�ű�ţ�";
	cin >> ID;
	cout << "�������ϼ����ű�ţ�";
	cin >> SENIORID;
	cout << "�����뱸ע��";
	cin >> REMARKS;
	string SQL = "INSERT INTO department VALUES ('" + NAME + "'," + ID + "," + SENIORID + ",'" + REMARKS + "')";
	int Res=DEPARTDB.executeSql(SQL);
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

void department::Modify()
{
	AdoCenter DEPARTDB;
	cout << "������Ҫ�޸ĵĲ������ƣ�";
	cin >> NAME;
	string SQL = "SELECT * FROM  department where NAME='" + NAME + "'";
	vector<string> Result;
	int res = DEPARTDB.selectData(SQL, Result);
	if (Result.size() != 0 && res != -1)
	{
		cout << "           ����            ���   �ϼ����    ��ע" << endl;
		for (int i = 0; i < Result.size(); i++)
		{
			cout << replace_all(string(Result[i]), ",", "          ") << endl;
		}
		cout << "�������޸ĺ�Ĳ������ƣ�";
		cin >> NAME;
		cout << "�������޸ĺ�Ĳ��ű�ţ�";
		cin >> ID;
		cout << "�������޸ĺ���ϼ����ű�ţ�";
		cin >> SENIORID;
		cout << "�������޸ĺ�ı�ע��";
		cin >> REMARKS;
		SQL = "UPDATE department SET `NAME`='"+NAME+"',ID="+ID+",SENIORID="+SENIORID+",REMARKS='"+REMARKS+"' WHERE `NAME`='"+NAME+"';";
		int Res = DEPARTDB.executeSql(SQL);
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
	else
	{
		cout << "δ��ѯ���ü�¼!!!" << endl;
	}
	CreatePage();
}

void department::Query()
{
	AdoCenter DEPARTDB;
	cout << "�����벿�����ƣ�";
	cin >> NAME;
	string SQL = "SELECT * FROM  department where NAME='" + NAME + "'";
	vector<string> Result;
	int res = DEPARTDB.selectData(SQL, Result);
	if (Result.size() != 0 && res != -1)
	{
		cout << "           ����            ���   �ϼ����    ��ע" << endl;
		for (int i = 0; i < Result.size(); i++)
		{
			cout << replace_all(string(Result[i]),",","          ") << endl;
		}
		SQL = "SELECT C.* FROM department AS A LEFT JOIN workers AS B on A.ID=B.DEPAERTID  JOIN attendance AS C on B.`NAME`=C.`NAME` WHERE A.`NAME`='" + NAME + "'; ";
		Result.clear();
		res = DEPARTDB.selectData(SQL, Result);
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
		}

	}
	else
	{
		cout << "δ��ѯ���ü�¼!!!" << endl;
	}
	CreatePage();
}