#include "stdafx.h"
#include "LoginPage.h"
using namespace std;
using namespace adosql;
LoginPage::LoginPage()
{

}

LoginPage::~LoginPage()
{

}
void LoginPage::CreatePage()
{
	rename("EOF", "adoEOF"), rename("BOF", "adoBOF");
	cout << "****************��ӭʹ�ÿ��ڹ���ϵͳ*****************" << endl;
	cout << "�������û�����";
	cin >> UserName;
	cout << "���������룺";
	cin >> PassWord;
	AdoCenter AdminDB;
	AdminDB.connect();
	string SQL = "SELECT * FROM  administrator where ( NAME='"+UserName+"' and PASSWORD = '"+PassWord+"')";
	//cout << SQL;
	vector<string> Result;
	int res=AdminDB.selectData(SQL, Result);
	//cout << Result.size();
	if(Result.size()!=0&&res!=-1)
	{
		cout << "��¼�ɹ�!!!"<<endl;
		HOMEPAGE.CreatePage();
	}	
	else
	{
		cout << "�˺Ż��������������������" << endl;
		CreatePage();
	}
}

