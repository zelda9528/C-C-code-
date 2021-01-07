#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char datatype;

//�������Ľ��   ������
typedef struct BinaryTreeNode 
{
	Node* left;
	Node* right;
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
Node* Creattree(datatype arr[],int* idx)
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
	printf("\n");
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
	printf("\n");
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
	printf("\n");
}

//������������
void BTreeSize(Node* root)
{
	if (root == NULL)
		return 0;
	return BTreeSize(root->left) + BTreeSize(root->right) + 1;
}

void test()
{
	char arr[] = "ABD##E#H##CF##G##";
	int idx = 0;
	Node* root = Creattree(arr, &idx);
	preorder(root);
	inorder(root);
}

int main()
{
	test();
	return 0;
}






