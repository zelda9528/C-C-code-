#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<assert.h>
using namespace std;




class String {
public:
	//ȫȱʡ���캯��
	String(const char* str="")
	{
		_size = strlen(str);
		_data = new char[_size + 1];
		_capacity = _size;

		strcpy(_data, str);
	}

	//�ִ�д���Ŀ�������
	String(const String & str):_data(nullptr),_size(0),_capacity(0)
	{
		//������ʱ����
		String tmp(str._data);
		Swap(tmp);
	}

	//�ִ�д�����ظ�ֵ�����
	String& operator=(String str)
	{
		Swap(str);
		return *this;
	}


	char& operator[](size_t pos)
	{
		assert(pos < _size);
		return _data[pos];
	}

	const char& operator[](size_t pos) const
	{
		assert(pos < _size);
		return _data[pos];
	}


	void Swap(String & str)
	{
		swap(_data, str._data);
		swap(_size, str._size);
		swap(_capacity, str._capacity);
	}


	size_t size()const
	{
		return _size;
	}


	//������---��ָ������
	//��*�����ã����ɷ�������
	//�ƶ���++iterator��--iterator
	//ʵ�֣��ַ�ָ��
	typedef char* iterator;
	typedef const char* const_iterator;
	iterator begin()
	{
		//��Ԫ��λ��
		return _data;
	}
	iterator end()
	{
		//���һ��Ԫ�ص���һ��λ��
		return _data + _size;
	}


	//reserve
	void reserve(size_t n)
	{
		if (n > _capacity)
		{
			//����ռ�
			char*tmp = new char[n + 1];
			//����
			strcpy(tmp, _data);
			//�ͷ�ԭ���ռ�
			delete[] _data;
			_data = tmp;
			_capacity = n;
		}
	}

	//β��
	void push_back(const char&ch)
	{
		//���ռ�
		if (_size == _capacity)
		{
			size_t newC=_capacity==0?15:2*_capacity;
			reserve(newC);
		}
		_data[_size++] = ch;

		//��ӽ����ַ�'\0'
		_data[_size] = '\0';
	}

	//resize
	void resize(size_t n,const char& ch='\0')
	{
		//3.n>_capacity    ��Ҫ����
		if (n > _capacity)
		{
			reserve(n);
		}

		//2._szie<n<=_capcity
		if(n>_size)
			memset(_data + _size, ch, (n - _size) * sizeof(char));

		//1.ֱ���޸�_size
		_size = n;

		_data[_size] = '\0';

	}


	//append
	void append(const char*str)
	{
		//�������
		int len = strlen(str);
		if (_size + len > _capacity)
		{
			reserve(_size + len);
		}
		//β��
		memcpy(_data + _size, str, sizeof(char) *len); //��srcpy����Ч
		//strcpy(_data + _size, str);

		//����size
		_size += len;
		_data[_size] = '\0';
	}


	//����+=�����
	String& operator+=(const char& ch)
	{
		push_back(ch);
		return *this;
	}

	String& operator+=(const char* str)
	{
		append(str);
		return *this;
	}

	String& operator+=(const String& str)
	{
		append(str._data);
		return *this;
	}
	
	void insert(size_t pos, const char&ch)
	{
		//���λ��
		assert(pos >= 0 && pos <= _size);
		//�������
		if (_size == _capacity)
		{
			size_t newC = _capacity == 0 ? 15:2*_capacity ;
			reserve(newC);
		}

		//�ƶ�Ԫ��:[pos,_size]�Ӻ���ǰ�ƶ�
		for (size_t i = _size; i >= pos; i--)
		{
			_data[i + 1] = _data[i];
		}
		//����Ԫ��
		_data[pos] = ch;

		//����
		_size++;

		_data[_size] = '\0';

	}
	//void insert(size_t pos, const char*ch)
	
	//void insert(size_t pos, const char*ch)







	//��������
	~String()
	{
		if (_data)
		{
			delete[] _data;
			_data = nullptr;
			_size = 0;
			_capacity = 0;
		}
	}


private:
	char* _data;

	//size����Ч�ַ��ĸ���
	size_t _size;
	//����
	size_t _capacity;
};

String operator+(const String& str1,const String & str2)
{
	String ret;
	ret += str1;
	ret += str2;

	return  ret;
}

String operator+(const String& str1, const char* ch)
{
	String ret;
	ret += str1;
	ret += ch;
	return ret;
}
String operator+(const String& str1, const char& str)
{
	String ret;
	ret += str1;
	ret += str;
	return ret;
}



void test()
{
	String str1("111");
	String str2("222");
	String str3, str4, str5;
		str3 = str1 + 'a';
		str4 = str1 + str2;
		str5 = str1 + "aaa";

		str1.insert(1,'a');




		//String str("123456");
	    //String str2("222");
	    //str.push_back('a');
	    //str.push_back('a');
	    //str.push_back('a');
		//str += 'c';
		//str += "111";
		//str.resize(3);
		//str.resize(10,'x');
		//str.resize(20,'b');
		//str.append("zxcv");

}
//
//void test()
//{
//	String str("0123456789");
//	cout << "forѭ����";
//	for (size_t i = 0; i < str.size(); i++)
//	{
//		cout  << str[i] << " ";
//	}
//	cout << endl;
//
//	cout << "��Χfor��";
//  //��Χfor�ǵ���string��begin��end��������ʵ�ֵ�
//	for (const auto& ch : str)
//	{	
//		cout  << ch <<" ";
//	}
//	cout << endl;
//
//	String::iterator it = str.begin();
//	cout << "��������";
//
//	while (it != str.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//}

int main()
{
	test();
	return 0;
}




//class String {
//public:
//
//
//	//ȫȱʡ�Ĺ��캯��
//	String(const char*str = "")
//		: _data(new char[strlen(str) + 1])
//	{
//		strcpy(_data, str);
//	}
//
//	//��������-�ִ�д��
//	String(const String&str):_data(nullptr)
//	{
//		String tmp(str._data);
//		swap(tmp._data, _data);
//	}
//
//	//��ֵ���������
//	/*String& operator=(const String&str)
//	{
//		String tmp(str._data);
//		swap(tmp._data, _data);
//		return *this;
//	}*/
//
//	//�ִ�д��
//	String& operator=( String str)
//	{
//		swap(str._data, _data);
//		return *this;
//
//	}
//
//	//c_str()
//	const char* c_str()const
//	{
//		return _data;
//
//	}
//
//	//��������
//	/*~String()
//	{
//		if (_data)
//		{
//			delete[] _data;
//			_data = nullptr;
//		}
//	}*/
//
//
//
//private:
//	char* _data;
//};
//
//
//void test()
//{
//	String str1 = "123123";
//	String str2 = str1;
//	String str3 = "123";
//
//	str3 = str1;
//
//}
