#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef int Datatype;



//���
typedef struct Listnode {
	Datatype data;
	struct Listnode*prev;
	struct Listnode*next;
}Listnode;

//˫���ͷѭ������
typedef struct List {
	struct Listnode*head;
 }List;


void Listinsert(struct Listnode* node, Datatype val);
void Listerase(Listnode*node);


//��ʼ��
void Init(List* lst)
{
	//����ѭ���ṹ
	//����ͷ���
	lst->head = (Listnode*)malloc(sizeof(struct Listnode));
	//ѭ��
	lst->head->prev = lst->head->next = lst->head;
}


//�����½��
struct Listnode*Creatnode(Datatype val)
{
	struct Listnode*node = (struct Listnode*)malloc(sizeof(struct Listnode));
	node->data = val;
	node->next = node->prev = NULL;
	return node;
}

//β��
void Pushback(List*lst, Datatype val)
{
	////��ǰβ���
	//Listnode*tail = lst->head->prev;
	//Listnode*newnode = Creatnode(val);

	////����
	//tail->next = newnode;
	//newnode->prev = tail;
	//newnode->next = lst->head;
	//lst->head->prev = newnode;

	Listinsert(lst->head, val);

}

//βɾ
void Popback(List*lst)
{
	if (lst->head->next == lst->head)
		return;
	////��β���
	//struct Listnode*tail = lst->head->prev;
	////ɾ��
	//lst->head->prev = tail->prev;
	//lst->head->prev->next = lst->head;
	//free(tail);

	Listerase(lst->head->prev);
}

//��ӡ����
void Print(List*lst)
{
	struct Listnode*cur = lst->head->next;
	while (cur != lst->head)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//ͷ��
void Pushfront(List*lst, Datatype val)
{
	//struct Listnode*newnode = Creatnode(val);
	//struct Listnode*next = lst->head->next;

	//lst->head->next = newnode;
	//newnode->prev = lst->head;
	//next->prev = newnode;
	//newnode->next = next;

	Listinsert(lst->head->next, val);
}


//ͷɾ
void Popfront(List* lst)
{
	if (lst->head->next == lst->head)
		return;
	//struct Listnode* next = lst->head->next->next;

	//lst->head->next = next;
	//next->prev = lst->head;

	Listerase(lst->head->next);
}

//��ѯ
struct Listnode *Find(List* lst, Datatype val)
{
	if (lst->head->next == lst->head)
		return NULL;
	struct Listnode*cur = lst->head->next;
	while (cur != lst->head&&cur->data != val)
	{
		cur = cur->next;	
	}
	return cur;
}


//������֮ǰ����
void Listinsert(struct Listnode* node, Datatype val)
{
	struct Listnode*newnode = Creatnode(val);
	struct Listnode*prev = node->prev;

	newnode->next = node;
	node->prev = newnode;
	prev->next = newnode;
	newnode->prev = prev;
}

//ɾ������һ�����
void Listerase( Listnode*node)
{
	struct Listnode*next = node->next;
	struct Listnode*prev = node->prev;

	prev->next = next;
	next->prev = prev;
	free(node);
}


//��������
void Destory(List*lst)
{
	struct Listnode*cur = lst->head->next;
	while (cur != lst->head)
	{
		free(cur);
		cur = cur->next;
	}
	free(lst->head);
}

//
void test()
{
	struct List lst;
	Init(&lst);
	//β��
	Pushback(&lst, 1);
	Pushback(&lst, 2);
	Pushback(&lst, 3);
	Pushback(&lst, 4);
	Pushback(&lst, 5);
	Print(&lst);

	//ͷ��
	Pushfront(&lst, 0);
	Pushfront(&lst, 0);
	Pushfront(&lst, 0);
	Print(&lst);

	//βɾ
	Popback(&lst);
	//ͷɾ
	Popfront(&lst);
	Popfront(&lst);
	Popfront(&lst);


	Print(&lst);

}

int main()
{
	test();
	return 0;
}