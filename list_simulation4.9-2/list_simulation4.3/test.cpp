#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

#include<string>
using namespace std;


template <class T>
//�ṹ�壺����Ľ��
struct ListNode {
	
	T data_;				//����
	ListNode<T>* next_;		//ͷָ��
	ListNode<T>* prev_;		//βָ��

	ListNode(const T&val=T()) :data_(val), next_(nullptr), prev_(nullptr)
	{}
};



//�Զ������͵�����
template<class T>
struct ListIterator {
	typedef ListNode<T> Node;
	//��װ���
	Node * node_;

	ListIterator(Node* node) :node_(node)
	{}

	//*iterator   ����*�����ʵ���Զ������͵������Ľ�����
	T& operator*()
	{
		return node_->data_;
	}

	//++iterator
	ListIterator<T>& operator++()
	{
		node_ = node_->next_;
		return *this;
	}
	

	//iterator++
	ListIterator<T> operator++(int)
	{
		ListIterator<T> tmp=*this;
		node_ = node_->next_;
		return tmp;
	}

	//--iterator
	ListIterator<T> operator--()
	{
		node_ = node_->prev_;
		return *this;
	}

	//iterator--
	ListIterator<T> operator--(int )
	{
		ListIterator<T> tmp = *this;
		node_ = node_->prev_;
		return tmp;
	}

	//operator!=
	bool operator!=(const ListIterator<T>& it)
	{
		return node_ != it.node_;
	}

	//operator==
	bool operator==(const ListIterator<T>& it)
	{
		return node_ == it.node_;

	}

};


//listʵ�֣�˫���ͷѭ������
template <class T>
class List {

public:
	typedef ListNode<T> Node;			//�ڵ�ı���
	typedef Node* pNode;				//���ָ��ı���
	typedef ListIterator<T> iterator;	//�Զ������͵�����


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

	iterator begin()
	{
		//����һ������������
		iterator it(header_->next_);
		return it;
		//return iterator(header_->next_);
	}

	iterator end()
	{
		iterator it(header_->prev_);
		return ++it;
		//iterator(header_->prev_);
	}

	//������ָ��Ľڵ��ͷţ��ᵼ�µ�����ʧЧ 
	//���µ�����
	//����ֵ��iterator--->��ɾ��Ԫ�ص���һ��λ��
	iterator eraser(iterator pos)
	{
		//�ж��Ƿ�Ϊ��Чλ��
		if (pos != end())
		{
			Node* cur = pos.node_;
			Node* next = cur->next_;
			Node* prev = cur->prev_;

			next->prev_ = prev;
			prev->next_ = next;

			delete pos.node_;

			return iterator(next);
		}
		return pos;
	}

	void popBack()
	{
		eraser(--end());
	}

	void popFront()
	{
		eraser(begin());
	}
	

	void insert(iterator pos,const T& val)
	{
		Node* cur = pos.node_;
		Node* prev = cur->prev_;

		Node* newnode=new Node(val);

		prev->next_ = newnode;
		newnode->prev_ = prev;
		newnode->next_ = cur;
		cur->prev_ = newnode;

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
		//cout << "~List()" << endl;
	}
	
	//��������
	List(const List<T>& lst):header_(new Node())
	{
		//ѭ���ṹ
		header_->next_ = header_->prev_ = header_;
		
		/*Node* cur = lst.header_->next_;
		while (cur != lst.header_)
		{
			Node* newnode = cur->data_;
			pushBack(newnode);
		}*/

		for (auto&e : lst)
		{
			pushBack(e);
		}
	}


	//��ֵ���������
	/*List<T>& operator=(const List<T>&lst)
	{
		List<T>::iterator it = lst.begin();
		while (it != lst.end())
		{
			pushBack(*it);
		}
	}*/

private:
	ListNode<T>* header_;	//ͷָ��
};

template <class T>
void PrintList(List<T>&lst)
{
	List<T>::iterator it = lst.begin();
	while (it != lst.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}



void test()
{
	List<int> lst;
	lst.pushBack(1);
	lst.pushBack(2);
	lst.pushBack(3);
	lst.pushBack(4);
	lst.pushBack(5);
	lst.pushBack(6);
	lst.pushBack(7);
	lst.pushBack(8);

	List<int>newlst;
	newlst = lst;

}

//void test()
//{
//	List<int> lst;
//	lst.pushBack(1);
//	lst.pushBack(2);
//	lst.pushBack(3);
//	lst.pushBack(4);
//	lst.pushBack(5);
//	lst.pushBack(6);
//	lst.pushBack(7);
//	lst.pushBack(8);
//
//	
//	lst.popBack();	//1234567
//	PrintList(lst);
//
//	lst.popFront();	//234567
//	PrintList(lst);
//}

//void test()
//{
//	List<int> lst;
//	lst.pushBack(1);
//	lst.pushBack(2);
//	lst.pushBack(3);
//	lst.pushBack(4);
//	lst.pushBack(5);
//	lst.pushBack(6);
//	lst.pushBack(7);
//	lst.pushBack(8);
//
//
//	List<int>::iterator it = lst.begin();
//	while (it != lst.end())
//	{
//		if (*it % 2 == 0)
//			it = lst.eraser(it);
//		else
//			++it;
//	}
//
//	lst.insert(lst.begin(), 0);
//
//	PrintList(lst);
//}

//void test()
//{
//	List<int> lst;
//	lst.pushBack(1);
//	lst.pushBack(1);
//	lst.pushBack(1);
//	lst.pushBack(1);
//	lst.pushBack(1);
//	lst.pushBack(2);
//	lst.pushBack(2);
//	lst.pushBack(2);
//	lst.pushBack(2);
//	lst.pushBack(2);
//
//
//	List<int>::iterator it = lst.begin();
//	while (it != lst.end())		//it.operator!=(lst.end())
//	{
//		cout << *it << " ";		//it.operator*()
//		++it;					//it.operator++()
//		//it++;					//it.operator++(int)
//	}
//	cout << endl;
//
//}

//void test()
//{
//	List<int>lst;
//	lst.pushBack(1);
//	lst.pushBack(2);
//	lst.pushBack(3);
//	lst.pushBack(4);
//
//	List<int>lst2(10, 5);
//
//	string str = "abcdef";
//	List<char>lst3(str.begin(),str.end());
//
//}

int main()
{
	test();
	return 0;
}