// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#import "C:\Program Files (x86)\Common Files\System\ado\msado15.dll" rename("EOF", "EndOfFile")


#include "targetver.h"
#include <stdio.h>

#include<algorithm>
#include <tchar.h>
#include <iostream>
#include <typeinfo>
#include <string>
#include <assert.h>
#include<vector>

#include <sstream>
#include"attendquery.h"
#include"department.h"
#include"attendence.h"
#include"worker.h"
#include "HomePage.h"
#include"LoginPage.h"
#include "DB.h"

class administrator;
class LoginPage;
string& replace_all(string& str, const string& old_value, const string& new_value);
// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
