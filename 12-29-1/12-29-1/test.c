#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef int stdatatype;

typedef struct stack {
	stdatatype* data;
	int size;
	int capacity;
}stack;

//��ʼ��
void Initstack(stack* st)
{
	if (st == NULL)
		return;
	st->data = NULL;
	st->capacity = st->size = 0;
}

//�������
void Checkcapacity(stack*st)
{
	if (st->size == st->capacity)
	{
		int newcapacity = st->capacity == 0 ? 1 : 2 * st->capacity;
		st->data = (stdatatype*)realloc(st->data, sizeof(stdatatype)*newcapacity);
		st->capacity = newcapacity;
	}
}

//��ջ
void Stackpush(stack* st, stdatatype val)
{
	if (st == NULL)
		return;
	Checkcapacity(st);
	st->data[st->size++] = val;
}

//��ջ
void Stackpop(stack* st)
{
	if (st == NULL || st->size == 0)
		return;
	st->size--;
}

//��ȡջ��Ԫ�ظ���
int Satcksize(stack* st)
{
	if (st == NULL)
		return 0;
	return st->size;
}

//�ж�ջ��
int Emptystack(stack*st)
{
	if (st == NULL || st->size == 0)
		return 1;
	else
		return 0;
}

//��ȡջ��Ԫ��
stdatatype Stacktop(stack* st)
{
	return st->data[st->size - 1];
}

bool isValid(char * s) {
	char map[3][2] = { {'(',')'},{'[',']'},{'{','}'} };
	struct stack st;
	Initstack(&st);
	while (*s)
	{
		int flag = 0;
		//������-��ջ
		for (int i = 0; i < 3; i++)
		{
			if (*s == map[i][0])
			{
				Stackpush(&st, *s);
				//�ж���һ���ַ�
				++s;
				flag = 1;
				break;
			}
		}
		//������-ƥ��
		if (flag == 0)
		{
			if (Emptystack(&st))
				return false;
			//ȡ��ջ��Ԫ��
			char topchar = Stacktop(&st);
			Stackpop(&st);
			for (int i = 0; i < 3; i++)
			{
				if (map[i][1] == *s)
				{
					if (topchar == map[i][0])
					{
						++s;
						break;
					}
					else
					{
						return false;//��ƥ��
					}
				}
			}
		}
	}
	//��ջΪ�� ��ʾ��ȫ�պ�
	return Emptystack(&st);
}