#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int Qdatatype;

typedef struct Qnode {
	Qdatatype data;
	struct Qnode* next;
}Qnode;


typedef struct Queue {

	//ͷβָ��
	struct Qnode*head;
	struct Qnode*tail;


}Queue;




//��ʼ��
void Queueinit(Queue* q)
{
	if (q == NULL)
		return;
	q->head = q->tail = NULL;
}


//�����½��
struct Qnode* creatnode(Qdatatype val)
{
	struct Qnode* node = (struct Qnode*)malloc(sizeof(struct Qnode));
	node->data = val;
	node->next = NULL;
	return node;
}


//���-β��
void Queuepush(Queue* q, Qdatatype val)
{
	if (q == NULL)
		return;
	// β��
	struct Qnode*node = creatnode(val);
	if (q->head == NULL)
		q->head = q->tail = node;
	else
	{
		q->tail->next = node;
		q->tail = node;
	}
}


//����-ͷɾ
void Queuepop(Queue* q)
{
	if (q == NULL || q->head == NULL)
		return;
	//ͷɾ
	struct Qnode* next = q->head->next;
	free(q->head);
	q->head = next;
	//���ö���ֻ��һ����㣬βָ����Ҫ�ÿ�
	if (q->head == NULL)
		q->tail = NULL;
}


//��ȡ����Ԫ��
Qdatatype Queuefront(Queue* q)
{
	return q->head->data;
}


//��βԪ��
Qdatatype Queueback(Queue* q)
{
	return q->tail->data;
}


//�ж϶����Ƿ�Ϊ��
int Queueempty(Queue* q)
{
	if (q->head == NULL)
		return 1;
	else
		return 0;
}

//���д�С
int Queuesize(Queue* q)
{
	int n = 0;
	struct Qnode*p = q->head;
	while (p)
	{
		++n;
		p = p->next;
	}
	return n;
}



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
int BTreeKsize(Node* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BTreeKsize(root->left, k - 1) + BTreeKsize(root->right, k - 1);
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

//��������ʵ�ֶ������Ĳ������
void LevelOrder(Node* root)
{
	//�ö���ʵ�ֲ������
	Queue q;
	//��ʼ������
	Queueinit(&q);

	//���ڵ����
	Queuepush(&q, root);
	
	//����ÿһ�����
	while (!Queueempty(&q))
	{
		Node* front = Queuefront(&q);
		printf("%c ", front->data);
		Queuepop(&q);
		//�����������
		if (front->left)
			Queuepush(&q, front->left);
		if (front->right)
				Queuepush(&q, front->right);
	}
	printf("\n");
}

//�ж��Ƿ�Ϊ��ȫ������
//��ȫ�����������ʣ����������������ģ������ڳ���NULL֮���ֳ��ַǿս��
int IscompleteBTree(Node* root)
{
	Queue q;
	Queueinit(&q);
	if (root)
		Queuepush(&q, root);
	while (!Queueempty(&q))
	{
		Node* front = Queuefront(&q);
		Queuepop(&q);
		//���Һ������
		if (front)
		{
			Queuepush(&q, front->left);
			Queuepush(&q, front->right);
		}
		else
			break;
	}
	while (!Queueempty(&q))
	{
		Node* front = Queuefront(&q);
		if (front)
			//���ʣ��Ԫ���д��ڷǿս�㣬��֤��������ȫ������
			return 0;
	}
	return 1;
}
//int IscompleteBTree(Node* root)
//{
//	if (root == NULL)
//		return 0;
//	Queue q;
//	Queueinit(&q);
//
//	Queuepush(&q, root);
//	while (Queuefront(&q)!=NULL)
//	{
//		Node* front = Queuefront(&q);
//		Quuepop(&q);
//		if (front->left)
//			Queuepush(&q, front->left);
//		if (front->right)
//			Queuepush(&q, front->right);
//	}
//	while (!Queueempty(&q))
//	{
//		if (Queuefront(&q) == NULL)
//		{
//			Queuepop(&q);
//		}
//		
//	}
//
//}

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
	printf("��%d��Ľڵ������%d \n", 4, BTreeKsize(root, 4));


}


int main()
{
	test();
	return 0;
}

