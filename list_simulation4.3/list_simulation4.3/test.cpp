#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

#include<string>
using namespace std;

//listʵ�֣�˫���ͷѭ������


template <class T>
//�ṹ�壺����Ľ��
struct ListNode {
	
	T data_;				//����
	ListNode<T>* next_;		//ͷָ��
	ListNode<T>* prev_;		//βָ��

	ListNode(const T&val=T()) :data_(val), next_(nullptr), prev_(nullptr)
	{}
};

template <class T>
class List {

public:
	typedef ListNode<T> Node;	//�ڵ�ı���
	typedef Node* pNode;	//���ָ��ı���

	List():header_(new Node)
	{
		//ѭ���ṹ
		header_->next_ = header_->prev_ = header_;
	}

	List(int n, const T&val = T()):header_(new Node)
	{
		header_->next_ = header_->prev_ = header_;
		for (int i = 0; i < n; i++)
		{
			pushBack(val);
		}
	}
	void pushBack(const T&val)
	{
		Node*prev = header_->prev_;
		Node* newNode = new Node(val);

		prev->next_ = newNode;
		newNode->prev_ = prev;

		newNode->next_ = header_;
		header_->prev_ = newNode;
	}

	template <class inputIterator>
	List(inputIterator first, inputIterator last):header_(new Node)
	{	
		header_->next_ = header_->prev_ = header_;

		while (first != last)
		{
			pushBack(*first);
			first++;
		}
	}

	~List()
	{
		if (header_)
		{
			Node* node = header_->next_;
			while (node!=header_)
			{
				Node* next = node->next_;
				delete node;
				node = next;
			}
			delete header_;
			header_ = nullptr;
		}
		cout << "~List()" << endl;
	}
	
private:
	ListNode<T>* header_;	//ͷָ��
};

void test()
{
	List<int>lst;
	lst.pushBack(1);
	lst.pushBack(2);
	lst.pushBack(3);
	lst.pushBack(4);

	List<int>lst2(10, 5);

	string str = "abcdef";
	List<char>lst3(str.begin(),str.end());

}

int main()
{
	test();
	return 0;
}