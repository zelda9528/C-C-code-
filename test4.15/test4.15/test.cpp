#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<queue>
#include<functional>
using namespace std;



template<class T>
class PriorityQueue
{
public:
	//���µ���
	void shiftDown()
	{
		int parent = 0;
		int child = 2 * parent + 1;
		while (child < arr.size())
		{
			if (child + 1 < arr.size() && arr[child] < arr[child + 1])
			{
				child++;
			}
			if (arr[parent] < arr[child])
			{
				//����
				swap(arr[parent], arr[child]);
				//����λ��
				parent = child;
				child = 2 * parent + 1;
			}
			else
				break;
		}
	}

	//���ϵ���
	void shiftUp(int child)
	{
		int parent = (child - 1) / 2;
		while (child > 0 )
		{
			if (arr[parent] < arr[child])
			{
				swap(arr[parent], arr[child]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else 
				break;
		}

	}

	void push(const T&val)
	{
		arr.push_back(val);
		shiftUp(arr.size() - 1);
	}

	void pop()
	{
		//����
		swap(arr[0], arr[arr.size() - 1]);
		//βɾ
		arr.pop_back();
		//���µ���
		shiftDown();
	}

	T& top()
	{
		return arr.front();
	}

	size_t size()
	{
		return arr.size();
	}

	bool empty()
	{
		return arr.empty();
	}
private:
	vector<T>arr;

};

void test()
{
	PriorityQueue<int> pq;
	pq.push(1);
	pq.push(3);
	pq.push(9);
	pq.push(0);
	pq.push(30);
	pq.push(11);
	pq.push(6);

}

int main()
{
	test();
	return 0;
}