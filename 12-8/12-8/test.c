#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef int slDatatype;//˳����ڵ��������ͣ�����ά����

//��̬˳���
typedef struct seqList 
{
	slDatatype *data;  //����ָ��
	int size;           //��ЧԪ�ظ���
	int capacity;       //�����ڴ�ռ�

} seqList;

//��ʼ��˳���
void Init(seqList* sl)//�β�Ϊ�ṹ��ָ��
{
	sl->data = NULL;
	sl->size = 0;
	sl->capacity = 0;
}


//�������������
void Checkcapacity(seqList*sl)
{
	if (sl->size == sl->capacity)
	{
		//�����¿ռ�
		int newCapacity = sl->capacity == 0 ? 1 : 2 * sizeof(sl->capacity);
		slDatatype * tmp = (slDatatype*)malloc(newCapacity*sizeof(slDatatype));

		//��������
		memcpy(tmp, sl->data, sizeof(slDatatype)*sl->size);

		//�ͷ�ԭ�пռ�
		free(sl->data);
		sl->data = tmp;

	//��ʹ��realloc��̬���ٿռ䡪���������滻35-42��
		//sl->data = (seqList*)ralloc(sl->data, newCapacity * sizeof(slDatatype));

		//��������
		sl->capacity = newCapacity;

	}
}

//��ӡ˳���
void Listprint(seqList*sl)
{
	if (sl == NULL)
		return;
	for (int i = 0; i < sl->size; i++)
	{
		printf("%d ", sl->data[i]);
	}
	printf("\n");
}

//β��
void Pushback(seqList* sl,slDatatype val)
{
	if (sl == NULL)
		return;

	Checkcapacity(sl);

	sl->data[sl->size] = val;
	sl->size++;
}

//βɾ
void Popback(seqList* sl)
{
	if (sl == NULL||sl->size==0)
		return;
	if (sl->size > 0)
		sl->size--;
}


//ͷ��
void Pushfront(seqList*sl,slDatatype val)
{
	if (sl == NULL)
		return;

	//�������
	Checkcapacity(sl);
    
	//�ƶ�Ԫ��--�Ӻ���ǰ
	int end = sl->size;
	while (end > 0)
	{
		sl->data[end] = sl->data[end - 1];
		--end;
	}

	//����Ԫ��
	sl->data[0] = val;
	sl->size++;
}


//ͷɾ
void Popfront(seqList* sl)
{
	if (sl == NULL||sl->size==0)
		return;
	
	//��ǰ����ƶ�Ԫ��
	for (int i = 0; i < sl->size; i++)
	{
		sl->data[i] = sl->data[i + 1];
	}

	//����size
	sl->size--;
}

//����λ�ò���Ԫ��
void Insert(seqList*sl, int pos, slDatatype val)
{
	if (sl == NULL)
		return;
	Checkcapacity(sl);
	if (pos >= 0 && pos <= sl->size)
	{
		//�ƶ�����
		int end = sl->size;
		while (end > pos)
		{
			sl->data[end] = sl->data[end - 1];
			end--;
		}
		//��������
		sl->data[pos] = val;
		sl->size++;
	}
}

//ɾ������λ������
void Erase(seqList*sl, int pos)
{
	if (sl == NULL || sl->size == 0)
		return;
	if (pos >= 0 && pos < sl->size)
	{
		while (pos<sl->size)
		{
			sl->data[pos] = sl->data[pos+1];
			pos++;
		}
		sl->size--;
	}
}

//����ģ��
void test()
{
	seqList sl;
	Init(&sl);
	Pushback(&sl, 1);
	Pushback(&sl, 2);
	Pushback(&sl, 3);
	Pushback(&sl, 4);

	Erase(&sl, 1);
	Listprint(&sl);


}

//����˳���
void Destroy(seqList* sl)
{
	if (sl != NULL && sl->data != NULL)
	{
		free(sl->data);
		sl->data = NULL;
	}
}


int main()
{
	test();
	return 0;
}