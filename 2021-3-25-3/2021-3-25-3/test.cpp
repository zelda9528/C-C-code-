#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;


class String {
public:


	//ȫȱʡ�Ĺ��캯��
	String(const char*str = "")
		: _data(new char[strlen(str) + 1])
	{
		strcpy(_data, str);
	}

	//��������
	String(const String&str):_data(new char[strlen(str._data)+1])
	{
		//���
		strcpy(_data,str._data);
	}

	//��ֵ���������
	String& operator=(String &str)
	{
		if (this != &str)
		{
			//����ԭ�ռ�
			delete[]_data;
			//�����¿ռ�
			_data = new char[strlen(str._data) + 1];
			//��������
			strcpy(_data,str._data);
		}
		return *this;
	}


	//c_str()
	const char* c_str()const
	{ 
		return _data;
	}

	//��������
	~String()
	{
		if (_data)
		{
			delete [] _data;
			_data = nullptr;
		}
	}



private:
	char* _data;
};


void test()
{
	String str1 ("123123123");			//Ĭ�Ϲ���
	String str2(str1);					//��������

	String str3 ;
	str3 = str1;
}

int main()
{
	test();
	return 0;
}