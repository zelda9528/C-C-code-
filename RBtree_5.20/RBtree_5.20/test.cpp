#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

enum Color{
	BLACK,
	RED
};

template<class V>
struct RBTreeNode {
	RBTreeNode<V>* _left;
	RBTreeNode<V>* _right;
	RBTreeNode<V>* _parent;
	V _val;
	Color _color;

	RBTreeNode(const V&val = V())
		:_parent(nullptr)
		,_left(nullptr)
		,_right(nullptr)
		,_val(val)
		,_color(RED)
	{}
};

//KeyOfVal:ͨ��V��ȡ���Ӧ��Kֵ
template<class K, class V, class KeyOfVal>
class RBTree {
public:
	typedef RBTreeNode<V> Node;

	RBTree() :_header(new Node)
	{
		_header->_left = _header->_right = _header;
	}

	bool insert(const V&val)
	{
	//�����������Ĳ���

		if (_header->_parent == nullptr)
		{
			//���������
			Node* root = new Node(val);

			_header->_parent = root;
			root->_parent = _header;
			_header->_left = _header->_right = root;
			
			//������Ǻ�ɫ
			root->_color = BLACK;
			return true;
		}

		//�Ӹ��ڵ㿪ʼ����
		Node* cur = _header->_parent;
		Node* parent = nullptr;

		KeyOfVal kov;
		while (cur)
		{
			parent = cur;
			if (kov(cur->_val)==kov(val))
			{
				//keyֵ�������ظ�
				return false;
			}
			else if (kov(cur->_val) > kov(val))
			{
				cur = cur->_left;
			}
			else
			{
				cur = cur->_right;
			}
		}

		//����������Ľ��
		cur = new Node(val);
		if (kov(parent->_left) == kov(cur->_val))
			parent->_left = cur;
		else
			parent->_right = cur;
		cur->_parent = parent;

	//�޸���ɫ������ṹ

		//�ж��Ƿ��к�ɫ�����Ľ��
		while (cur != _header->_parent&&cur->_parent->_color == RED)
		{
			parent = cur->_parent;
			Node* gfather = parent->_parent;
			
			//���뷢�����游�������ʱ
			if (gfather->_left == parent)
			{

				Node* uncle = gfather->_right;

				//1.uncle���ڲ����Ǻ�ɫ
				if (uncle&&uncle->_color == RED)
				{
					parent->_color = uncle->_color = BLACK;
					gfather->_color = RED;

					//�������ϸ���
					if (gfather != _header->parent)
						cur = gfather;
				}
				else
				{
					//�ж��Ƿ�Ϊ˫��
					if (cur == parent->_right)
					{
						//����
						RotateL(parent);
						//����cur��parent
						swap(cur, parent);
					}
					//����
					RotateR(gfather);
					gfather->_color = RED;
					parent->_color = BLACK;
					break;
				}	
			}

			//���뷢�����游�����ұ�ʱ
			else
			{

			}

		}
		_header->_parent->_color = BLACK;
		_header->_left = leftMost();
		_header->_right = rightMost();
		return true;
	}

	Node* leftMost()
	{
		Node* cur = _header->_parent;
		while (cur&&cur->_left)
		{
			cur = cur->_left;
		}
		return cur;
	}
	Node* rightMost()
	{
		Node* cur = _header->_parent;
		while (cur&&cur->_right)
		{
			cur = cur->_right;
		}
		return cur;
	}

	void inorder()
	{
		_inorder(_header->_parent);
		cout << endl;
	}
	void _inorder(Node* root)
	{
		_inorder(root->_left);
		cout << root->_val<<" ";
		_inorder(root->_right);
	}

	//����
	void RotateL(Node* cur)
	{
		Node* curR = cur->_right;
		Node* curRL = curR->_left;

		curR->_left = cur;
		cur->_right = curRL;

		if (curRL)
		{
			curRL->_parent = cur;
		}
		if (cur == _header->parent)
		{
			_header->parent = curR;
			curR->_parent = _header;
		}
		else
		{
			Node* pparent = cur->_parent;
			if (pparent->_left == cur)
				pparent->_left = curR;
			else
				pparent->_right = curR;
			curR->_parent = pparent;
		}
		cur->_parent = curR;
	}


	//����
	void RotateR(Node* cur)
	{
		Node* curL = cur->_left;
		Node* curLR = curL->_right;

		curL->_right = cur;
		cur->_left = curLR;
		if (curLR)
		{
			curLR->_parent = cur;
		}
		if (cur == _header->parent)
		{
			_header->parent = curL;
			curL->_parent = _header;
		}
		else
		{
			Node* pparent = cur->_parent;
			if (pparent->_left == cur)
				pparent->_left = curL;
			else
				pparent->_right = curL;
			curL->_parent = pparent;
		}
		cur->_parent = curL;
	}
	
	

private:
	Node* _header = nullptr;
};

void test()
{

}

int main()
{
	return 0;
}