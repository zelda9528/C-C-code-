#pragma once
#include "stdafx.h"


using namespace ADODB;

namespace adosql
{
	class  AdoCenter
	{
	public:
		AdoCenter();
		~AdoCenter();
		//select����
		int selectData(const string& sql, vector<string>& results);

		//ִ��delete��insert�Ȳ���
		int executeSql(const string& sql);
		bool connect();
		bool reConnect();
	private:
		_ConnectionPtr m_pConn;
		_RecordsetPtr m_pRecordset;
		string m_connStr="test";
		string m_userId="root";
		string m_pwd="sun19990908";
	};
}