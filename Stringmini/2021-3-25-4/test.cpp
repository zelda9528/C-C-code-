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
		/*int end = _size;
		while (end > pos)
		{
			_data[end + 1] = _data[end];
			end--;
		}*/

		if (pos == 0)
		{
			for (size_t j = _size+1; j > 0; j--)
			{
				_data[j] = _data[j-1];
			}
		}
		else
		{
			for (size_t i = _size; i > pos; i--)
			{
				_data[i + 1] = _data[i];
			}
		}
		//����Ԫ��
		_data[pos] = ch;

		//����
		_size++;

		_data[_size] = '\0';

	}
	void insert(size_t pos, const char*ptr)
	{
		//���λ��
		assert(pos <= _size);
		//�������
		int len = strlen(ptr);
		if (_size + len > _capacity)
		{
			reserve(_size + len);
		}
		//�ƶ�Ԫ��
		size_t end = _size + len;
		while (end > pos + len - 1)
		{
			_data[end] = _data[end - len];
			--end;
		}
		//����
		memcpy(_data + pos, ptr, sizeof(char)*len);
		//����
		_size += len;
		_data[_size] = '\0';
	}
	
	void erase(size_t pos, size_t len)
	{
		//���λ��
		if (len > _size)
		{
			len = _size;
		}
		assert(pos < _size);
		//�ƶ�Ԫ��
		//��ǰ����ƶ�[pos+1,_size]
		size_t begin = pos + len;
		while (begin < _size)
		{
			_data[pos++] = _data[begin++]; 
		}
		//����
		_size -= len;

		_data[_size] = '\0';
		
	}


	size_t find(const char& ch, size_t pos = 0)
	{
		for (size_t i = 0; i < _size; i++)
		{
			if (_data[i] == ch)
				return i;
		}
		return -1; //��ʾû�ҵ�
	}

	size_t find(const char* str, size_t pos = 0)
	{
		//strstr����ֵ��
		//����NULL����ʾδ�ҵ�
		//������Ч��ַ����ʾ�Ӵ����ֵ��׵�ַ

		char*ptr= strstr(_data,str);
		if (ptr)
		{
			return ptr - _data;
		}
		else
			return -1;
	}

	/*ostream& operator<<(ostream&out)
	{
		for (const char&ch : *this)
			out << ch << " ";
		cout << endl;
		return out;
	}*/


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

ostream& operator<<(ostream&out, String&str)
{
	for (const char&ch : str)
		out << ch << " ";
	cout << endl;
	return out;
}

istream& operator>>(istream&in, String&str)
{
	char ch;
	while (ch=getchar())
	{
		if (ch == ' ' || ch == '\n' || ch == '\t')
			break;
		str += ch;
	}
	return in;
}



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
		String str2("abc");
		String str3;
		cin >> str3;

		str1.insert(0,'a');
		str1.insert(0,'b');
		str1.insert(0, "xxx");

		str1.erase(0,3);
		//str1.erase(0, 60);
		//str2 << (str1 << cout);
		cout << str1 << str2 << str3;




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





