//��С��ʵ��


#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef int datatype;
typedef struct heap 
{
	datatype* data;
	int size;
	int capacity;
}heap;

//��ʼ����
void Heap_init(heap*hp)
{
	if (hp == NULL)
		return;
	hp->data = NULL;
	hp->size = hp->capacity = 0;
}

//�������
void Check_capacity(heap* hp)
{
	if (hp->size == hp->capacity)
	{
		//��������
		hp->capacity = hp->capacity == 0 ? 1 : 2 * hp->capacity;
		//��̬�����µĿռ� 
		hp->data = (datatype *)realloc(hp->data, sizeof(datatype)*hp->capacity);
	}
}

//���µ����㷨---����С��Ϊ��
void Shift_down(int *arr, int n, int curpos) //n-�����С   curpos-��Ҫ������λ��
{
	//����
	int child = 2 * curpos + 1;
	while (child < n)
	{
		if (child + 1 < n&&arr[child + 1] < arr[child])
			child++;
		//���±Ƚ�
		if (arr[child] < arr[curpos])
		{
			int tmp = arr[child];
			arr[child] = arr[curpos];
			arr[curpos] = tmp;

			//�������±Ƚ�
			curpos = child;
			child = 2 * curpos + 1;
		}
		else
			break;
	}

}


//���ϵ����㷨
void Shift_up(int* arr, int n, int curpos)
{
	//���ڵ��λ��
	int parent = (curpos - 1) / 2;
	while (curpos > 0)
	{
		//�͸��ڵ�Ƚ�
		if (arr[curpos] < arr[parent])
		{
			int tmp = arr[curpos];
			arr[curpos] = arr[parent];
			arr[parent] = tmp;

			//����λ��
			curpos = parent;
			parent = (curpos - 1) / 2;
		}
		else
			break;		//��������
	}
}


//�ѵĲ���
void Heap_push(heap* hp, datatype val)
 {
	//�������
	Check_capacity(hp);
	//β��
	hp->data[hp->size++] = val;
	
	//���ϵ���
	Shift_up(hp->data, hp->size, hp->size - 1);
}




//��������
void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//�ѵ�ɾ��
void Heap_pop(heap*hp)
{
	if (hp == NULL || hp->size == 0)
		return;
	//����
	Swap(&hp->data[0], &hp->data[hp->size - 1]);
	//βɾ
	hp->size--;
	//���µ���
	Shift_down(hp->data, hp->size, 0);
}

//�ж϶ѿ�
int Heap_empty(heap*hp)
{
	if (hp == NULL || hp->size == 0)
		return 1;
	else
		return 0;
}

//��ȡ�Ѷ�Ԫ��
datatype Heap_top(heap*hp)
{
	return hp->data[0];
}

//������
void Creat_heap(int *arr, int n)
{
	for (int i = 0; i < (n - 2) / 2; i++)
	{
		Shift_down(arr, n, i);
	}
}

void test()
{
	heap hp;
	Heap_init(&hp);
	Heap_push(&hp, 28);
	Heap_push(&hp, 29);
	Heap_push(&hp, 45);
	Heap_push(&hp, 46);
	Heap_push(&hp, 25);
	Heap_push(&hp, 38);
	Heap_push(&hp, 19);
	Heap_push(&hp, 8);

	Heap_pop(&hp);
	Heap_pop(&hp);
	Heap_pop(&hp);
	Heap_pop(&hp);

	while (!Heap_empty(&hp))
	{
		printf("%d ", Heap_top(&hp));
		Heap_pop(&hp);
	}
	printf("\n");

 }

int main()
{
	test();
	return 0;
}

