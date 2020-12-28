//����

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>


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
void Init(Queue* q)
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
void Queuepush(Queue* q,Qdatatype val)
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
	if (q == NULL||q->head==NULL)
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

void test()
{
	Queue q;
	Init(&q);
	Queuepush(&q, 1);
	Queuepush(&q, 2);
	Queuepush(&q, 3);
	Queuepush(&q, 4);
	Queuepush(&q, 5);
	Queuepush(&q, 6);
	Queuepush(&q, 7);
	Queuepush(&q, 8);

	while (!Queueempty(&q))
	{
		printf("%d ", Queuefront(&q));
		Queuepop(&q);
	}
	printf("\n");

}
int main()
{
	test();
	return 0;
}