#define _CRT_SECURE_NO_WARNINGS 1


#include "contact.h"


void check_capacity(Contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		//��������
		PeoInfo* ptr = (PeoInfo*)realloc(pc->data, (pc->capacity + INC) * sizeof(PeoInfo));
		if (ptr != NULL)
		{
			pc->data = ptr;
			pc->capacity += INC;
			printf("���ݳɹ�\n");
		}
		else
		{
			perror("add_contact::realloc");
			return;
		}
	}
}




void load_contact(Contact* pc)
{
	PeoInfo tmp = { 0 };//��ʱ�ռ�
	FILE* pfRead = fopen("contact.dat", "rb");
	if (pfRead == NULL)
	{
		perror("open file for reading");
		return;
	}
	//��������
	while (fread(&tmp, sizeof(PeoInfo), 1, pfRead))
	{
		check_capacity(pc);
		pc->data[pc->sz] = tmp;
		pc->sz++;
	}


	fclose(pfRead);
	pfRead = NULL;
}


void init_contact(Contact* pc)
{
	assert(pc);
	pc->sz = 0;
	pc->capacity = DEFAULT_SZ;
	pc->data = (PeoInfo*)malloc(DEFAULT_SZ * sizeof(PeoInfo));
	if (pc->data == NULL)
	{
		perror("InitContact::malloc");
		return;
	}
	//����ͨѶ¼����Ϣ
	load_contact(pc);
}


void destroy_contact(Contact* pc)
{
	assert(pc);
	free(pc->data);
	pc->data = NULL;
	pc->capacity = 0;
	pc->sz = 0;
}


//
//void add_contact(Contact* pc)
//{
//	if (pc->sz == MAX)
//	{
//		printf("ͨѶ¼����\n");
//	}
//	else
//	{
//		printf("����������:>");
//		scanf("%s", pc->data[pc->sz].name);
//		printf("������绰:>");
//		scanf("%s", pc->data[pc->sz].tele);
//		printf("�������ַ:>");
//		scanf("%s", pc->data[pc->sz].addr);
//		printf("������QQ:>");
//		scanf("%s", pc->data[pc->sz].qq);
//		printf("�������Ա�:>");
//		scanf("%s", pc->data[pc->sz].sex);
//		printf("����������:>");
//		scanf("%d", &(pc->data[pc->sz].age));
//
//		pc->sz++;
//		printf("��ӳɹ�\n");
//	}
//}






void add_contact(Contact* pc)
{
	assert(pc);
	check_capacity(pc);
	//
	printf("����������:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("������绰:>");
	scanf("%s", pc->data[pc->sz].tele);
	printf("�������ַ:>");
	scanf("%s", pc->data[pc->sz].addr);
	printf("������QQ:>");
	scanf("%s", pc->data[pc->sz].qq);
	printf("�������Ա�:>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("����������:>");
	scanf("%d", &(pc->data[pc->sz].age));


	pc->sz++;
	printf("��ӳɹ�\n");
}






void show_contact(Contact* pc)
{
	assert(pc);


	int i = 0;
	printf("%10s %12s %20s %5s %12s %5s\n", "����", "�绰", "��ַ", "����", "QQ", "�Ա�");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%10s %12s %20s %5d %12s %5s\n", pc->data[i].name,
			pc->data[i].tele,
			pc->data[i].addr,
			pc->data[i].age,
			pc->data[i].qq,
			pc->data[i].sex);
	}
}


static int find_peo_by_name(Contact* pc, char name[])
{
	assert(pc);


	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(name, pc->data[i].name) == 0)
		{
			return i;//�ҵ��ˣ������±�
		}
	}
	return -1;//�Ҳ���
}


void del_contact(Contact* pc)
{
	assert(pc);


	if (pc->sz == 0)
	{
		printf("��Ǹ��ͨѶ¼Ϊ��\n");
	}
	else
	{
		char name[MAX_NAME] = { 0 };
		printf("������Ҫɾ���˵�����:>");
		scanf("%s", name);
		//1. �ҵ�ָ������ϵ�˵�λ��
		int pos = find_peo_by_name(pc, name);
		if (pos == -1)
		{
			printf("���ź���ɾ�����˲�����\n");
		}
		else
		{
			//2. ɾ��
			int j = 0;
			for (j = pos; j < pc->sz - 1; j++)
			{
				pc->data[j] = pc->data[j + 1];
			}
			pc->sz--;
			printf("ɾ���ɹ�\n");
		}
	}
}




void search_contact(Contact* pc)
{
	assert(pc);


	char name[MAX_NAME] = { 0 };
	printf("������Ҫ�����˵�����:>");
	scanf("%s", name);
	int pos = find_peo_by_name(pc, name);
	if (pos == -1)
	{
		printf("���޴���\n");
	}
	else
	{
		printf("%10s %12s %20s %5s %12s %5s\n",
			"����", "�绰", "��ַ", "����", "QQ", "�Ա�");
		printf("%10s %12s %20s %5d %12s %5s\n", pc->data[pos].name,
			pc->data[pos].tele,
			pc->data[pos].addr,
			pc->data[pos].age,
			pc->data[pos].qq,
			pc->data[pos].sex);
	}
}




void modify_contact(Contact* pc)
{
	assert(pc);


	char name[MAX_NAME] = { 0 };
	printf("������Ҫ�޸��˵�����:>");
	scanf("%s", name);
	int pos = find_peo_by_name(pc, name);
	if (pos == -1)
	{
		printf("���޴���\n");
	}
	else
	{
		printf("�������µ�����:>");
		scanf("%s", pc->data[pos].name);
		printf("�������µĵ绰:>");
		scanf("%s", pc->data[pos].tele);
		printf("�������µĵ�ַ:>");
		scanf("%s", pc->data[pos].addr);
		printf("�������µ�QQ:>");
		scanf("%s", pc->data[pos].qq);
		printf("�������µ��Ա�:>");
		scanf("%s", pc->data[pos].sex);
		printf("�������µ�����:>");
		scanf("%d", &(pc->data[pos].age));
	}
}


void sort_contact(Contact* pc)
{
	int i = 0;
	int j = 0;
	assert(pc);


	for (i = 0; i < pc->sz - 1; i++)
	{
		int flag = 1;//�����Ѿ�����
		for (j = 0; j < pc->sz - 1 - i; j++)
		{
			if (strcmp(pc->data[j].name, pc->data[j + 1].name) > 0)
			{
				PeoInfo tmp = pc->data[j];
				pc->data[j] = pc->data[j + 1];
				pc->data[j + 1] = tmp;
				flag = 0;
			}
		}
		if (1 == flag)
		{
			break;
		}
	}
}




void save_contact(Contact* pc)
{
	int i = 0;
	FILE* pfWrite = fopen("contact.dat", "wb");
	if (pfWrite == NULL)
	{
		perror("open file for writting");
		return;
	}
	//д����
	for (i = 0; i < pc->sz; i++)
	{
		fwrite(pc->data + i, sizeof(PeoInfo), 1, pfWrite);
	}
	fclose(pfWrite);
	pfWrite = NULL;
}