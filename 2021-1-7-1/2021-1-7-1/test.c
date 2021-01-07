#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char datatype;

//�������Ľ��   ������
typedef struct BinaryTreeNode
{
	struct Node* left;
	struct Node* right;
	datatype data;
}Node;

typedef struct BTree
{
	//���������ڵ�
	Node* root;
}BTree;

////��������
//void Creat_tree(BTree* bt)
//{
//	bt->root = NULL;
//}

//���������������ظ��ڵ�
Node* Creattree(datatype arr[], int* idx)
{
	if (arr[*idx] == '#')
	{
		(*idx)++;
		return NULL;
	}
	//��ǰ���ĸ��ڵ�
	Node* root = (Node*)malloc(sizeof(Node));
	root->data = arr[*idx];
	(*idx)++;
	//������������
	root->left = Creattree(arr, idx);
	root->right = Creattree(arr, idx);
	return root;
}

//ǰ�����
void preorder(Node* root)
{
	if (root)
	{
		//ǰ�򣺸�->��->��
		printf("%c ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

//�������
void inorder(Node* root)
{
	if (root)
	{
		//������->��->��
		inorder(root->left);
		printf("%c ", root->data);
		inorder(root->right);
	}
}


//�������
void postorder(Node* root)
{
	if (root)
	{
		//������->��->��
		postorder(root->left);
		postorder(root->right);
		printf("%c ", root->data);
	}
}

//������������
int BTreeSize(Node* root)
{
	if (root == NULL)
		return 0;
	return BTreeSize(root->left) + BTreeSize(root->right) + 1;
}

//���ĸ߶�
int BTreeHigh(Node* root)
{
	if (root == NULL)
		return 0;
	//���ĸ߶�=�����������нϴ�Ķȣ�+1
	int left = BTreeHigh(root->left);
	int right = BTreeHigh(root->right);
	return left > right ? left + 1 : right + 1;
}

//������Ҷ�ӽڵ�ĸ���
int BTreeLeaf(Node* root)
{
	//����
	if (root == NULL)
		return 0;
	//����ֻ��һ�����
	if (root->left == NULL && root->right == NULL)
		return 1;
	//һ�����
	return BTreeLeaf(root->left) + BTreeLeaf(root->right);
}


//��K�������=����������k-1��ڵ�����ĺ�   ��Ϊ��һ��
int BTreeKsize(Node* root,int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BTreeKsize(root->left,k-1)+BTreeKsize(root->right,k-1);
}

//����������
Node* BTreeFind(Node* root, datatype ch)
{
	if (root)
	{
		if (root->data == ch)
			return root;
		Node* node = BTreeFind(root->left, ch);
		if (node)
			return node;
		else
			return BTreeFind(root->right, ch);
	}
	else
		return NULL;
}

//���ٶ�����
void DestoryBTree(Node* root)
{
	if (root)
	{
		DestoryBTree(root->left);
		DestoryBTree(root->right);
		free(root);
		root = NULL;
	}
}

void test()
{
	char arr[] = "ABD##E#H##CF##G##";
	int idx = 0;
	Node* root = Creattree(arr, &idx);
	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
	printf("���Ľ�������%d \n", BTreeSize(root));
	printf("���Ķȣ�%d \n", BTreeHigh(root));
	printf("Ҷ�ӽڵ�ĸ�����%d \n", BTreeLeaf(root));
	printf("��%d��Ľڵ������%d \n",4, BTreeKsize(root,4));

}

int main()
{
	test();
	return 0;
}






