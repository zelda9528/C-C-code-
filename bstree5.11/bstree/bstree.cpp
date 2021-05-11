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

	//ɾ��
	bool erase(const T& val)
	{
		//����
		Node* cur = root_;
		Node* parent = nullptr;
		while (cur)
		{
			if (cur->data_ == val)
				break;
			parent = cur;
			if (cur->data_ > val)
				cur = cur->left;
			else
				cur = cur->right;
		}
		//�ж���Ҫɾ���Ľ���Ƿ��ҵ�
		if (cur == nullptr)
			return false;
		
		//ɾ��
		//1.ɾ����ΪҶ�ӽڵ�
		if (cur->left == nullptr&&cur->right == nullptr)
		{
			//�ж��Ƿ�Ϊ�����
			if (cur == root_)
			{
				root_ = nullptr;
			}
			else
			{
				//�ж���Ҫɾ���Ľ���ڸ��ڵ���һ��
				if (parent->left == cur)
					parent->left = nullptr;
				else
					parent->right = nullptr;
			}
			//ɾ�����
			delete cur;
		}

		//2.ɾ����Ϊ��Ҷ�ӽ��:
		//2.1������Ϊ��
		else if(cur->left==nullptr)
		{
			//�жϸ�����Ƿ�ΪҪɾ���Ľ��
			if (cur == root_)
			{
				root_ = cur->right;
			}
			else
			{
				//��������
				if (parent->left == cur)
					parent->left = cur->right;
				else
					parent->right = cur->right;
			}
			//ɾ�����
			delete cur;
		}
		//2.2������Ϊ��
		else if (cur->right == nullptr)
		{
			//�жϸ�����Ƿ�ΪҪɾ���Ľ��
			if (cur == root_)
			{
				//���¸����
				root_ = cur->left;
			}
			else
			{
				//��������
				if (parent->left == cur)
					parent->left = cur->left;
				else
					parent->right = cur->left;
			}
			//ɾ�����
			delete cur;
		}
		//2.3Ҫɾ���Ľ�������Һ���
		else
		{
			//1.�����������������ҽ��
			Node* leftRightMost = cur->left;
			parent = cur;
			while (leftRightMost->right)
			{
				parent = leftRightMost;
				leftRightMost = leftRightMost->right;
			}
			//2.����
			swap(cur->data_, leftRightMost->data_);
			//3.ɾ�����ҽ��
			if (parent->left == leftRightMost)
				parent->left = leftRightMost->left;
			else
				parent->right = leftRightMost->left;

			delete leftRightMost;
		}

		//else
		//{
		//	Node* RIGHT = cur->right;
		//	if (RIGHT->left == nullptr)
		//		RIGHT->left = cur->left;
		//	else
		//		RIGHT->left->left = cur->left;
		//	//�ж�Ҫɾ���Ľ���Ƿ�Ϊ�����
		//	if (cur == root_)
		//	{
		//		root_ = RIGHT;		//���¸����
		//		delete cur;
		//		return true;
		//	}
		//	if (parent->left == cur)
		//		parent->left = RIGHT;
		//	else
		//		parent->right = RIGHT;
		//	delete cur;
		//}
		
		return true;
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

	b.insert(5);
	b.insert(3);
	b.insert(7);
	b.insert(1);
	b.insert(4);
	b.insert(6);
	b.insert(8);
	b.insert(0);
	b.insert(2);
	b.insert(9);
	b.insert(90);
	b.insert(19);
	b.insert(28);
	b.insert(32);
	b.insert(56);
	b.insert(34);
	b.insert(21);
	b.insert(33);

	b.erase(5);



	b.inorder();


}

//void test()
//{
//	BTree<int> b;
//
//	b.insert(15);
//	b.insert(6);
//	b.insert(18);
//	b.insert(3);
//	b.insert(7);
//	b.insert(17);
//	b.insert(20);
//	b.insert(2);
//	b.insert(9);
//	b.insert(4);
//	b.insert(13);
//
//	BTree<int> a(b);
//
//	b.inorder();
//	cout << endl;
//
//
//}

int main()
{
	test();
	return 0;
}