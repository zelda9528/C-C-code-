#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef int ldatatype;

//�����㣺����+ָ��
typedef struct listnode
{
	ldatatype data;
	struct listnode* next;

}listnode;

//��������
typedef struct list
{
	//ͷ���ĵ�ַ
	listnode* head;
}list;

//��ʼ������
void initlist (list*lst)
{
	if (lst == NULL)
		return;
	lst->head = NULL;
}


//�������
listnode* creat_listnode(ldatatype val)
{
	listnode* node = (listnode*)malloc(sizeof(listnode));
	node->data = val;
	node->next = NULL;
	return node;
}


//β��
void pushback(list* lst, ldatatype val)
{
	if (lst == NULL)
		return;
	if (lst->head == NULL)
	{
		lst->head = creat_listnode(val);
	}
	else
	{    
		//�����ҵ����һ�����
		listnode* tail = lst->head;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = creat_listnode(val);
	}

}

//βɾ
void popback(list* lst)
{
	if (lst == NULL)
		return;
	//�����������һ�����
	listnode*pre = NULL;
	listnode*tail = lst->head;
	while (tail->next != NULL)
	{
		pre = tail;
		tail = tail->next;
	}
	//�ͷ����һ�����
	free(tail);
	//β���ÿ�

	if (pre == NULL)//���������ֻ��һ�����
		lst->head = NULL;
	else
	pre->next = NULL;
}

//ͷ��
void pushfront(list*lst, ldatatype val)
{
	if (lst == NULL)
		return;
	//�����½ڵ�
	listnode* node = creat_listnode(val);
	//����
	node->next = lst->head;
	lst->head = node;
}

//ͷɾ
void popfront(list*lst)
{
	if (lst == NULL || lst->head == NULL)
		return;
	listnode*next = lst->head->next;
	//�ͷſռ�
	free(lst->head);
	//����headָ�� 
	lst->head = next;
}


//������λ�õĺ������Ԫ��
void insert_after(listnode*node, ldatatype val)
{
	if (node == NULL)
		return;
	listnode*newnode = creat_listnode(val);
	listnode*next = node->next;
	node->next = newnode;
	newnode->next = next;
}

//ɾ��ĳһ������һ�����
void erase_after(listnode* node)
{
	if (node == NULL || node->next == NULL)
		return;
	listnode*next = node->next;
	listnode*nextnext = next->next;

	free(next);
	node->next = nextnext;
}


//����
listnode* find(list*lst,ldatatype val)
{
	if (lst == NULL || lst->head == NULL)
		return NULL;
	listnode*pos = lst->head;
	while (pos)
	{
		if (pos->data == val)
			return pos;
		else
			pos = pos->next;
	}
	return NULL;

}

//�������н��
void destory(list* lst)
{
	if (lst == NULL||lst->head==NULL)
		return;
	listnode*pos = lst->head;
	listnode*next = pos->next;

	while (pos)
	{
		free(pos);
		pos = next;
		next = next->next;
	}
}



int main()
{
	list lst;
	initlist(&lst);
	pushfront(&lst, 5);
	pushfront(&lst, 4);
	pushfront(&lst, 3);
	pushfront(&lst, 2);
	pushfront(&lst, 1);


	pushback(&lst, 0);
	pushback(&lst, 0);
	pushback(&lst, 0);
	pushback(&lst, 0);
    
	return 0;
}