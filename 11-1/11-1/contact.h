#define _CRT_SECURE_NO_WARNINGS 1


//
//���͵�����+����������
//

#include <stdio.h>
#include <string.h>

#define MAX 1000

#define MAX_NAME 20
#define MAX_TELE 12
#define MAX_ADDR 100
#define MAX_QQ 12
#define MAX_SEX 5

typedef struct PeoInfo
{
	char name[MAX_NAME];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
	char qq[MAX_QQ];
	char sex[MAX_SEX];
	short age;
}PeoInfo;

//ͨѶ¼
typedef struct Contact
{
	PeoInfo data[MAX];//����
	int sz;//��Ч����
}Contact;


//���һ���˵���Ϣ
void add_contact(Contact* pc);

//��ʾͨѶ¼�е���Ϣ
void show_contact(Contact* pc);

//ɾ��ָ������ϵ��
void del_contact(Contact* pc);

//����ָ����ϵ��
void search_contact(Contact* pc);

//�޸�ָ����ϵ��
void modify_contact(Contact* pc);

//����ͨѶ¼������
void sort_contact(Contact* pc);
