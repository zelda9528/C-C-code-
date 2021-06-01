#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<memory>
#include<thread>
#include<mutex>
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


//shared_ptr:
//1.֧�ָ�ֵ�Ϳ���
//2.ͨ�����ü�����֤��Դ��ȷ�ͷ��Ҳ��ᱻ����ͷ�
//3.�ڶ��߳��У�ͨ�������ü������д��в������ӽ���������֤�������µ���ȷ��
//4.ÿһ����Դ�����Լ����������ü���
template<class T>
class SharedPtr {
private:
	T* _ptr;
	size_t* _countPtr;
	mutex* _mtx;	//ÿһ����Դ����һ����������
public:
	SharedPtr(T* ptr)
		:_ptr(ptr)
		, _countPtr(new size_t(1))
		,_mtx(new mutex)
	{}

	SharedPtr(const SharedPtr<T>& sp)
		:_ptr(sp._ptr)
		, _countPtr(sp._countPtr)
		, _mtx(sp._mtx)
	{
		//�������ۼ�
		//++(*_countPtr);
		addCount();
	}

	SharedPtr<T> operator=(const SharedPtr<T>& sp)
	{
		if (_ptr != sp._ptr)	//�ж��Ƿ�Ϊ��ͬ��Դ��ָ�룬�����ͬһ����Դ������Ҫ���²���
		{
			//ԭ�������Լ�
			//����������Լ���Ϊ0����ʾ��ǰ���������һ���������Դ��
			//�������Դ�����ͷ�
			//if (--(*_countPtr) == 0)
			if(subCount()==0)
			{
				delete _ptr;
				delete _countPtr;
				delete _mtx;
			}
			_ptr = sp._ptr;
			_countPtr = sp._countPtr;

			//�¼��������ۼ�
			//++(*_countPtr);
			addCount();
		}
		return *this;
	}

	~SharedPtr()
	{
		//�ο����ü���
		//if (--(*_countPtr) == 0)
		if(subCount()==0)
		{
			delete _ptr;
			delete _countPtr;
			delete _mtx;
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

	size_t getCount()
	{
		return *_countPtr;
	}

	size_t addCount()
	{
		_mtx->lock();
		++(*_countPtr);
		_mtx->unlock();
		return *_countPtr;
	}
	size_t subCount()
	{
		_mtx->lock();
		--(*_countPtr);
		_mtx->unlock();
		return *_countPtr;
	}

};

void fun(const SharedPtr<Data>&sp, int n)
{
	for (int i = 0; i < n; i++)
		SharedPtr<Data> copy(sp);
}

void test()
{
	cout << "test:" << endl;
	SharedPtr<Data> Sp(new Data);
	SharedPtr<Data> Sp2(new Data);

	int n = 10000;
	thread t1(fun, ref(Sp), n);
	thread t2(fun, ref(Sp), n);
	thread t3(fun, ref(Sp), n);
	thread t4(fun, ref(Sp), n); 

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	

	cout << Sp.getCount() << endl;
	cout << Sp2.getCount() << endl;

}

int main()
{
	test();
	return 0;
}