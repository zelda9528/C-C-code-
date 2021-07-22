#include "stdafx.h"
#include "worker.h"

using namespace adosql;
worker::worker()
{
}


worker::~worker()
{
}
void worker::CreatePage()
{
	cout << "*******************��ӭʹ�����¹�����*******************" << endl;
	cout << "+++++++++          1.��ѯԱ����Ϣ             +++++++++" << endl;
	cout << "+++++++++          2.����Ա����Ϣ             +++++++++" << endl;
	cout << "+++++++++          3.�޸�Ա����Ϣ             +++++++++" << endl;
	cout << "+++++++++          4.ɾ��Ա����Ϣ             +++++++++" << endl;
	cout << "+++++++++          5.������һ����             +++++++++" << endl;
	cout << "**********************************************************" << endl;
	int In = 0;
	cout << "������ָ�";
	cin >> In;
	switch (In)
	{
	case 1:Query(); break;
	case 2:Add(); break;
	case 3:Modify(); break;
	case 4:Delete(); break;
	case 5:return; break;
	default:
		CreatePage();
		break;
	}
}

void worker::Add()
{
	AdoCenter WORKERDB;
	cout << "������Ա��������";
	cin >> NAME;
	cout << "������Ա����ţ�";
	cin >> ID;
	cout << "������Ա���Ա�";
	cin >> GENDER;
	cout << "������Ա�����գ�";
	cin >> BIRTHDAY;
	cout << "������Ա�����ű�ţ�";
	cin >> DEPAERTID;

	string SQL = "INSERT INTO workers VALUES('"+NAME+"',"+ID+",'"+GENDER+"','"+BIRTHDAY+"',"+DEPAERTID+")";
	int Res = WORKERDB.executeSql(SQL);
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
void worker::Delete()
{
	AdoCenter WORKERDB;
	cout << "������Ա������(����)��";
	cin >> NAME;
	string SQL = "DELETE FROM workers WHERE (NAME = '" + NAME + "')";
	int Res = WORKERDB.executeSql(SQL);
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
void worker::Modify()
{
	AdoCenter WORKERDB;
	cout << "������Ҫ�޸ĵ�Ա��������";
	cin >> NAME;
	string SQL = "SELECT * FROM  workers where NAME='" + NAME + "'";
	vector<string> Result;
	int res = WORKERDB.selectData(SQL, Result);
	if (Result.size() != 0 && res != -1)
	{
		for (int i = 0; i < Result.size(); i++)
		{
			cout << replace_all(string(Result[i]), ",", "     ") << endl;
		}
		cout << "�������޸ĺ��Ա��������";
		cin >> NAME;
		cout << "�������޸ĺ��Ա����ţ�";
		cin >> ID;
		cout << "�������޸ĺ��Ա���Ա�";
		cin >> GENDER;
		cout << "�������޸ĺ��Ա�����գ�";
		cin >> BIRTHDAY;
		cout << "�������޸ĺ��Ա�����ű�ţ�";
		cin >> DEPAERTID;
		SQL = "UPDATE workers SET  `NAME`='"+NAME+"',ID="+ID+",GENDER='"+GENDER+"',BIRTHDAY='"+BIRTHDAY+"',DEPAERTID="+ DEPAERTID +" WHERE `NAME`='"+NAME+"'";
		int Res = WORKERDB.executeSql(SQL);
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
void worker::Query()
{
	AdoCenter WORKERDB;
	cout << "������Ա������(����)��";
	cin >> NAME;
	string SQL = "SELECT A.`NAME`,A.ID,A.GENDER,A.BIRTHDAY,B.`NAME` FROM workers AS A LEFT JOIN department AS B ON A.DEPAERTID=B.ID WHERE A.`NAME`='"+NAME+"'";
	vector<string> Result;
	int res = WORKERDB.selectData(SQL, Result);
	if (Result.size() != 0 && res != -1)
	{
		cout << "����  ���   �Ա�  ����  ����" << endl;
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
	CreatePage();
}