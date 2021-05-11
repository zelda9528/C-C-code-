#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;
template <class K,class V>
struct BNode {
	//T data_;
	K  _key;		//����������
	V _value;		//������data_

	typedef BNode<K,V> Node;
	Node* left;
	Node* right;

	BNode(const K&key,const V&value) :_key(key),_value(value),left(nullptr), right(nullptr)
	{}
};

template<class K,class V>
class BTree {
public:
	typedef BNode<K,V> Node;
	BTree() :root_(nullptr)
	{}

	//�������ظ���ֵ
	bool insert(const K&key,const V&value)
	{
		if (root_ == nullptr)
		{
			root_ = new Node(key,value);
			return true;
		}

		//����
		Node* cur = root_;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (cur->_key == key)
				return false;
			else if (cur->_key > key)
				cur = cur->left;
			else
				cur = cur->right;
		}
		//����
		cur = new Node(key,value);
		if (parent->_key > key)
			parent->left = cur;
		else
			parent->right = cur;

		return true;
	}

	Node* find(const K& key)
	{
		Node* cur = root_;
		while (cur)
		{
			if (cur->_key == key)
				return cur;
			else if (cur->_key > key)
				cur = cur->left;
			else
				cur = cur->right;
		}
		return cur;
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
			cout << root_->_key << "-->"<<root_->_value<<" ";
			_inorder(root_->right);
		}
	}

	//�������������������ݺͽṹ
	Node* copy(Node* root)
	{
		if (root == nullptr)
			return nullptr;
		
		//������
		Node* newnode = new Node(root->_key,root->_value);
		//����������
		newnode->left = copy(root->left);
		//����������
		newnode->right = copy(root->right);

		return newnode;
	}

	//ɾ��
	bool erase(const K& key)
	{
		//����
		Node* cur = root_;
		Node* parent = nullptr;
		while (cur)
		{
			if (cur->_key == key)
				break;
			parent = cur;
			if (cur->_key > key)
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
		else if (cur->left == nullptr)
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
			swap(cur->_key, leftRightMost->_key);
			swap(cur->_value, leftRightMost->_value);

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
	BTree(const BTree<K,V>& btree) :root_(copy(btree.root_))
	{}

	void destroy(Node* root)
	{
		if (root)
		{
			destroy(root->left);
			destroy(root->right);
			cout << "destroy:" << root->_key <<"-->"<<root->_value<<endl;
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
	BTree<int, int>b;
	b.insert(5,50);
	b.insert(3, 50);
	b.insert(7, 50);
	b.insert(1, 50);
	b.insert(4, 50);
	b.insert(6, 50);
	b.insert(8, 50);
	cout << endl;

	b.inorder();
	

}


int main()
{
	test();
	return 0;
}