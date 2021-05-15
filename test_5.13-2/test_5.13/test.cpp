#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

using namespace std;

template <class T>
struct AVLNode {
	AVLNode<T>* parent_;
	AVLNode<T>* left_;
	AVLNode<T>* right_;	

	T val_;

	int bf_;			//ƽ������

	AVLNode(const T&val=T())
		:parent_(nullptr)
		,left_(nullptr)
		,right_(nullptr)
		,val_(val)
		,bf_(0)
	{}

private:
	AVLNode* root_ = nullptr;
};


template <class T>
struct AVLtree
{
public:
	typedef AVLNode<T> Node;
	bool insert(const T&val)
	{
		//�����������Ĳ���
		if (root_ == nullptr)
		{
			root_ = new Node(val);
			return true;
		}
		Node* cur = root_;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (cur->val_ == val)
				return false;
			else if (cur->val_ > val)
				cur = cur->left_;
			else
				cur = cur->right_;
		}
		cur = new Node(val);
		if (parent->val_ > val)
			parent->left_ = cur;
		else
			parent->right_ = cur;

		cur->parent_ = parent;

		//����
		while (parent)
		{
			//���¸��ڵ��ƽ������
			if (parent->left_ == cur)
				--parent->bf_;
			else
				++parent->bf_;

			if (parent->bf_ == 0)	//�����߶ȱ�����
				//��������
				break;
			else if (parent->bf_ == 1 || parent->bf_ == -1)
				//�������ϸ���
			{
				cur = parent;
				parent = parent->parent_;
			}
			else if (abs(parent->bf_) == 2)
			{
				if (parent->bf_ == -2 && cur->bf_ == -1)
				{
					//����������߸ߣ�����
					RotateR(parent);
				}
				break;
			}
		}
		return true;
	}

	void RotateR(Node* cur)
	{
		Node* curL = cur->left_;
		Node* curLR = curL->right_;

		curL->right_ = cur;
		cur->left_ = curLR;
		if (curLR)
		{
			curLR->parent_ = cur;
		}
		if (cur == root_)
		{
			root_ = curL;
			curL->parent_ = nullptr;		
		}
		else
		{
			Node* pparent = cur->parent_;
			if (pparent->left_ == cur)
				pparent->left_ = curL;
			else
				pparent->right_ = curL;
			curL->parent_ = pparent;
		}
		cur->parent_ = curL;
		curL->bf_ = cur->bf_ = 0;
	}

	void RotateL(Node* cur)
	{
		Node* curR = cur->right_;
		Node* curRL = curR->left_;

		curR->left_ = cur;
		cur->right_ = curRL;

		if (curRL)
		{
			curRL->parent_ = cur;
		}
		if (cur == root_)
		{
			root_ = curR;
			curR->parent_ = nullptr;
		}
		else
		{
			Node* pparent = cur->parent_;
			if (pparent->left_ == cur)
				pparent->left_ = curR;
			else
				pparent->right_ = curR;
			curR->parent_ = pparent;
		}
		cur->parent_ = curR;
		cur->bf_ = curR->bf_ = 0;
	}


private:
	Node* root_=nullptr;
};


void test()
{
	AVLtree<int> avl;
	avl.insert(5);
	avl.insert(3);
	

	avl.insert(1);//����  
	//       5
	//    3
	// 1
	
	//������
	//    3
	// 1      5

}

int main()
{
	test();
	return 0;
}








