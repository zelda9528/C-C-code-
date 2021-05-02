#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;
template <class T>
struct BNode {
	T data_;
	typedef BNode<T> Node;
	Node* left;
	Node* right;

	BNode(const T&data) :data_(data), left(nullptr), right(nullptr)
	{}

};

template<class T>
class BTree {
public:
	typedef BNode<T> Node;
	BTree():root_(nullptr)
	{}

	//�������ظ���ֵ
	bool insert(const T&val)
	{
		if (root_ == nullptr)
		{
			root_ = new Node(val);
			return true;
		}

		//����
		Node* cur = root_;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (cur->data_ == val)
				return false;
			else if (cur->data_ > val)
				cur = cur->left;
			else
				cur = cur->right;
		}
		//����
		cur = new Node(val);
		if (parent->data_ > val)
			parent->left = cur;
		else
			parent->right = cur;

		return true;
	}

	Node* find(const T& val)
	{
		Node* cur = root_;
		while (cur)
		{
			if (cur->data_ == val)
				return cur;
			else if (cur->data_ > val)
				cur = cur->left;
			else
				cur = cur->right;
		}
	}



	void inorder()
	{
		_inorder(root_);
	}

	//�������������������
	void _inorder(Node* root_)
	{
		if (root_)
		{
			_inorder(root_->left);
			cout << root_->data_ << " ";
			_inorder(root_->right);
		}
	}

	//�������������������ݺͽṹ
	Node* copy(Node* root)
	{
		if (root == nullptr)
			return nullptr;
		//������
		Node* newnode = new Node(root->data_);
		//����������
		newnode->left = copy(root->left);
		//����������
		newnode->right = copy(root->right);

		return newnode;
	}

	//�ڳ�Ա��ʼ���б�׶ε���copy()�������п�������
	BTree(const BTree<T>& btree):root_(copy(btree.root_))
	{}


	void destroy(Node* root)
	{
		if (root)
		{
			destroy(root->left);
			destroy(root->right);
			//cout << "destroy:" << root->data_ << " ";
			delete root;
		}
	}

	~BTree()
	{
		if (root_)
		{
			destroy(root_);
			root_ = nullptr;
		}
	}



private:
	Node* root_;
};




void test()
{
	BTree<int> b;

	b.insert(15);
	b.insert(6);
	b.insert(18);
	b.insert(3);
	b.insert(7);
	b.insert(17);
	b.insert(20);
	b.insert(2);
	b.insert(9);
	b.insert(4);
	b.insert(13);

	BTree<int> a(b);

	b.inorder();
	cout << endl;


}

int main()
{
	test();
	return 0;
}