#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<deque>
using namespace std;


template<class T,class Container=deque<T>>
class Queue {
public:
	//size  empty  back  push_back   pop_back
	void push(const T&val)
	{
		c.push_back(val);
	}
	void pop()
	{
		c.pop_front();
	}
	T& top()
	{
		return c.front();
	}
	bool empty()
	{
		return c.empty();
	}
	size_t size()
	{
		return c.size();
	}
private:
	Container c;
};

void test()
{
	//Queue<int>st;		//��д�ڶ���������Ĭ��ʹ��dequeʵ��
	Queue<int, list<int>>st;		//ָ��ʹ��list��ʵ��
	//Queue<int, vector<int>>st;	//ע��˴�������vector��ʵ��queue����Ϊvectorû��ͷɾ�ӿ�
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	cout << "size:" << st.size() << endl;

	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
	cout << "size:" << st.size() << endl;
}

int main()
{
	test();
	return 0;
}