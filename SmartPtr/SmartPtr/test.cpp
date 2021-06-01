#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<memory>
#include<thread>
using namespace std;
struct Data {
	int _y = 2021;
	int _m = 6;
	int _d = 1;

	~Data()
	{
		cout << "~Data()" << endl;
	}
};

//����ָ��
//ͨ��������������ڹ�����Դ����������
//����ָ���ʵ�֣�1.RAII˼�룻2.ʵ��'*'��'->'�������Ĺ���
template<class T>
class SmartPtr {
private:
	T* _ptr;
public:
	SmartPtr(T* ptr) :_ptr(ptr)
	{}

	~SmartPtr()
	{
		if (_ptr)
			delete _ptr;
		cout << "~SmartPtr()" << endl;
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

};
void test()
{
	cout << "test1:" << endl;
	SmartPtr<int> sp(new int);

	SmartPtr<Data> sp2(new Data);
	cout << "���ڣ�" << sp2->_y << '.' << sp2->_m << '.' << sp2->_d << endl;;

}

//ģ��ʵ��auto_ptr
template<class T>
class AutoPtr {
private:
	T* _ptr;
public:
	AutoPtr(T* ptr):_ptr(ptr)
	{}
	//����������Ȩת��
	AutoPtr(AutoPtr<T>& ap) :_ptr(ap._ptr)
	{
		ap._ptr = nullptr;
	}
	//��ֵ������Ȩת��
	AutoPtr<T>& operator=(AutoPtr<T>& ap)
	{
		if (this != &ap)
		{
			if (_ptr)
				delete _ptr;
			_ptr = ap._ptr;

			ap._ptr = nullptr;
		}
		return *this;
	}

	~AutoPtr()
	{
		if (_ptr)
			delete _ptr;
	}

};

void test2()
{
	cout << "test2:" << endl;

	//��׼������ָ��--���ڹ���Ȩת�����⣬���ͷű�������ָ�룬��ֹʹ��
	auto_ptr<int> ap(new int(10));
	auto_ptr<Data> ap2(new Data);
	ap2->_y = 1999;
	ap2->_m = 3;
	ap2->_d = 19;
	cout << "���ڣ�" << ap2->_y << '.' << ap2->_m << '.' << ap2->_d << endl;
	
	//����ָ��Ŀ�������:����Ȩת�Ƶ��µ�ָ��
	//���ָ�����ͬһ���ڴ�ռ䣬���ǲ�����ɶ����ͷŵ�����
	auto_ptr<Data> ap3 = ap2;
}
void test3()
{
	cout << "test3:" << endl;

	AutoPtr<Data> Ap1(new Data);
	AutoPtr<Data> Ap2(Ap1);		//�������죺����Ȩת��
}

//unique_ptr��ʵ��
template <class T>
class UniquePtr {
private:
	T* _ptr;
public:
	UniquePtr(T* ptr) :_ptr(ptr)
	{}

	//��ֹ�����͸�ֵ
	UniquePtr(const UniquePtr<T>& up) = delete;
	UniquePtr& operator=(const UniquePtr<T>& up) = delete;
	~UniquePtr()
	{
		if (_ptr)
			delete _ptr;
	}

};

void test4()
{
	
	//unique_ptr:�����������ܸ�ֵ
	//unique_ptr����������͸�ֵ���㶨��Ϊdelete����
	unique_ptr<Data> up(new Data);
	//unique_ptr<Data> up1(up);
	unique_ptr<Data> up3(new Data);
	//up3 = up;

}

template<class T>
class SharedPtr {
private:
	T* _ptr;
	size_t* _countPtr;
public:
	SharedPtr(T* ptr) 
		:_ptr(ptr)
		,_countPtr(new size_t(1))
	{}
	
	SharedPtr(const SharedPtr<T>& sp)
		:_ptr(sp._ptr)
		,_countPtr(sp._countPtr)
	{
		//�������ۼ�
		++(*_countPtr);
	}

	SharedPtr<T> operator=(const SharedPtr<T>& sp)
	{
		if (_ptr!=sp._ptr)	//�ж��Ƿ�Ϊ��ͬ��Դ��ָ�룬�����ͬһ����Դ������Ҫ���²���
		{
			//ԭ�������Լ�
			//����������Լ���Ϊ0����ʾ��ǰ���������һ���������Դ��
			//�������Դ�����ͷ�
			if (--(*_countPtr) == 0)
			{
				delete _ptr;
				delete _countPtr;
			}
			_ptr = sp._ptr;
			_countPtr=sp._countPtr;

			//�¼��������ۼ�
			++(*_countPtr);
		}
		return *this;
	}

	~SharedPtr()
	{
		//�ο����ü���
		if (--(*_countPtr) == 0)
		{
			delete _ptr;
			delete _countPtr;
		}
	}

	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
};

void test5()
{
	cout << "test5:" << endl;
	shared_ptr<Data> shp(new Data);
	cout << shp.use_count() << endl;

	shared_ptr<Data> shp2(shp);
	shared_ptr<Data> shp3(new Data);
	shp3 = shp;
	shp3 = shp2;
	cout << shp.use_count() << endl;

}

void test6()
{
	cout << "test6:" << endl;
	SharedPtr<Data> sp1(new Data);
	SharedPtr<Data> sp2(new Data);

	SharedPtr<Data> sp3(sp1);

	sp2 = sp1;
}
void fun(const SharedPtr<Data>&sp, int n)
{
	for (int i = 0; i < n; i++)
		SharedPtr<Data> copy(sp);
}

void test7()
{
	cout << "test7:" << endl;
	SharedPtr<Data> Sp(new Data);
	int n = 10;
	thread t1(fun, ref(Sp), n);
	thread t2(fun, ref(Sp), n);
	t1.join();
	t2.join();
}

int main()
{
	test();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	return 0;
} 