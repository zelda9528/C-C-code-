#include "stdafx.h"
#include "HomePage.h"


HomePage::HomePage()
{

}


HomePage::~HomePage()
{

}
void HomePage::CreatePage()
{
	while (1)
	{
		cout << "****************��ӭʹ�ÿ��ڹ���ϵͳ*****************" << endl;
		cout << "+++++++++          1.������Ϣ����           +++++++++" << endl;
		cout << "+++++++++          2.������Ϣ����           +++++++++" << endl;
		cout << "+++++++++          3.���ڻ��ܲ�ѯ           +++++++++" << endl;
		cout << "+++++++++          4.������Ϣ����           +++++++++" << endl;
		cout << "+++++++++          5.�˳�ϵͳ               +++++++++" << endl;
		cout << "*****************************************************" << endl;
		int In = 0;
		cout << "������ָ�";
		cin >> In;
		switch (In)
		{
		case 1:WORKER.CreatePage(); break;
		case 2:ATTENDENCE.CreatePage(); break;
		case 3:ATTENDQUERY.CreatePage(); break;
		case 4:DEPARTMENT.CreatePage(); break;
		case 5:return; break;
		default:
			break;
		}
	}
}