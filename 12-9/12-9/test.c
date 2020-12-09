#define _CRT_SECURE_NO_WARNINGS 1

// #include "stdafx.h"
#include <string.h>
#include <stdlib.h>
#include <tchar.h>
#include<stdio.h>

typedef enum { true = 1, false = 0 }bool;
#define MAX_PROCESS 10 //����������
#define MAX_RESOURCE_KIND 10 //��Դ��������
#define MAX_RESOURCE_NUM 20	//ÿ����Դ����������

int resource;	//ʵ����Դ������
int process;	//ʵ�ʽ�����
int safe_list[MAX_PROCESS];	//��ȫ����

struct AVAILABLE {	//������Դ����
	int resource_number; //��Դ��Ŀ
	int work;	//��������	
}Resource[MAX_RESOURCE_KIND], R_backup[MAX_RESOURCE_KIND];

struct PROC {	//��������������
	int max[MAX_RESOURCE_KIND];	//����������
	int allocation[MAX_RESOURCE_KIND];	//�������
	int need[MAX_RESOURCE_KIND];	//�������
	bool finish;	//������
}Process[MAX_PROCESS], P_backup[MAX_PROCESS];

void zero();
void show_me();
void init();
void init_allocation();
void update();
void backup();
void re_backup();
bool allocation();
bool one_allocation(int a, int b, int c);
bool release();
bool one_release(int a, int b, int c);
int is_safe();
void test();
int banker();
void menu();

void zero() {//����
	for (int i = 0; i < MAX_RESOURCE_KIND; i++) {
		Resource[i].resource_number = 0;
	}
	for (int i = 0; i < MAX_RESOURCE_KIND; i++) {
		for (int j = 0; j < MAX_RESOURCE_KIND; j++) {
			Process[i].max[j] = 0;
			Process[i].allocation[j] = 0;
			Process[i].need[j] = 0;
		}
	}
}


void show_me() {//���ƾ���
	printf("\n  Available����  ");
	for (int i = 0; i < resource; i++) {
		printf("%d ", Resource[i].resource_number);
	}
	printf("\n");
	printf("\n  Max����");
	for (int i = 0; i < MAX_RESOURCE_KIND * 2 - 7; i++) printf(" ");
	printf("Allocation����");
	for (int i = 0; i < MAX_RESOURCE_KIND * 2 - 14; i++) printf(" ");
	printf("Need����");
	for (int i = 0; i < MAX_RESOURCE_KIND * 2 - 8; i++) printf(" ");

	for (int i = 0; i < process; i++) {
		printf("\n  ");
		for (int j = 0; j < resource; j++) printf("%d ", Process[i].max[j]);
		for (int i = 0; i < MAX_RESOURCE_KIND * 2 - resource * 2; i++) printf(" ");
		for (int j = 0; j < resource; j++)	printf("%d ", Process[i].allocation[j]);
		for (int i = 0; i < MAX_RESOURCE_KIND * 2 - resource * 2; i++) printf(" ");
		for (int j = 0; j < resource; j++) printf("%d ", Process[i].need[j]);
	}
	printf("\n");
}


void init() {//��ʼ��
	int n;
	printf("\n������Դ������  ");
	scanf("%d", &n);
	resource = n;
	for (int i = 0; i < resource; i++) {
		printf("\n�����%d����Դ����  ", i + 1);
		scanf("%d", &n);
		Resource[i].resource_number = n;
	}
	printf("\n���������  ");
	scanf("%d", &n);
	process = n;
	for (int i = 0; i < process; i++) {
		int a, flag;
		flag = 0;
		printf("\n�������%d����Դʹ����Ŀ  ", i + 1);
		for (int j = 0; j < resource; j++) {
			scanf("%d", &a);
			Process[i].max[j] = a;
			if (a > Resource[j].resource_number) flag = 1;
		}
		if (flag == 1) {
			i--;
			printf("\n���󳬹���Դ��������������\n");
		}
		getchar();
	}
}

void init_allocation() {//��ʼ����״̬
	for (int i = 0; i < process; i++) {
		int a, flag;
		flag = 0;
		printf("\n�������%d��ǰ��Դռ�����  ", i + 1);
		for (int j = 0; j < resource; j++) {
			scanf("%d", &a);
			Process[i].allocation[j] = a;
			if (a > Resource[j].resource_number) flag = 1;
		}
		if (flag == 1) {
			i--;
			printf("\n��ǰ��Դռ�ó�����Դ��������������\n");
		}
	}
	update();
}


void update() {//�����������need����Դ����allocation
	for (int i = 0; i < process; i++) {
		for (int j = 0; j < resource; j++) {
			Process[i].need[j] = Process[i].max[j] - Process[i].allocation[j];
			Resource[j].resource_number -= Process[i].allocation[j];
		}
	}
}
bool allocation() {
	backup();
	printf("\n������ ���̺��Լ���Ӧ��Դ���������Ŀ�ÿո����\n");
	int pro_num;
	scanf("%d", &pro_num);
	int aff[MAX_RESOURCE_KIND];
	for (int i = 0; i < resource; i++) {
		scanf("%d", &aff[i]);
	}
	for (int i = 0; i < resource; i++) {
		if (one_allocation(pro_num - 1, i, aff[i]) == false) {//���õ��η��亯�����Է���
			re_backup();
			return false;
		}
	}
	return true;
}

bool one_allocation(int a, int b, int c) {//���η���
	if (c > Process[a].need[b]) {
		printf("Ҫ�󳬹��������ޣ�����ʧ��\n");
		return false;
	}
	else if (c > Resource[b].resource_number) {
		printf("���㹻��Դ������ʧ��\n");
		return false;
	}
	Resource[b].resource_number -= c;
	Process[a].need[b] -= c;
	Process[a].allocation[b] += c;
	return true;
}
void backup() {		//���ݱ���
	for (int i = 0; i < process; i++) {
		P_backup[i] = Process[i];
	}
	for (int i = 0; i < resource; i++) {
		R_backup[i] = Resource[i];
	}
}
void re_backup() {	//���ݻ�ԭ
	for (int i = 0; i < process; i++) {
		Process[i] = P_backup[i];
	}
	for (int i = 0; i < resource; i++) {
		Resource[i] = R_backup[i];
	}
}
bool release() {	//�ͷ���Դ
	backup();
	printf("\n������ ���̺��Լ���Ӧ��Դ���������Ŀ�ÿո����\n");
	int pro_num;
	scanf("%d", &pro_num);
	int aff[MAX_RESOURCE_KIND];
	for (int i = 0; i < resource; i++) {
		scanf("%d", &aff[i]);
	}
	for (int i = 0; i < resource; i++) {
		if (one_release(pro_num, i, aff[i]) == false) {
			re_backup();
			return false;
		}
	}
	return true;
}
bool one_release(int a, int b, int c) {//��Դ�ͷ�
	if (c > Process[a].allocation[b]) {
		printf("�ͷų����������ޣ�����ʧ��\n");
		return false;
	}
	Resource[b].resource_number += c;
	Process[a].need[b] += c;
	Process[a].allocation[b] -= c;
	return true;
}

int is_safe() {	//��ȫ�Լ���㷨

	for (int i = 0; i < resource; i++) {
		Resource[i].work = Resource[i].resource_number;
	}
	for (int i = 0; i < process; i++) {
		Process[i].finish = false;
		safe_list[i] = 0;
	}
	test();
	bool flag = true;
	for (int i = 0; i < process; i++) {
		if (Process[i].finish == false) {
			flag = false;
			break;
		}
	}
	if (flag == true) {
		printf("\nϵͳ״̬��ȫ");
		printf("\n��ȫ����Ϊ  ");
		for (int i = 0; i < process; i++) {
			printf("%d ", safe_list[i]);
		}
		return 1;
	}
	else {
		printf("\nϵͳ״̬����ȫ");
		return -1;
	}
}


void test() {	//��ȫ���㷨�ĵݹ��֧
	for (int i = 0; i < process; i++) {
		bool flag = true;
		if (Process[i].finish == false) {
			for (int j = 0; j < resource; j++) {
				if (Process[i].need[j] > Resource[j].work) {
					flag = false;
					break;
				}
			}
			if (flag == true) {
				for (int j = 0; j < resource; j++) {
					Resource[j].work += Process[i].allocation[j];
					Process[i].finish = true;
				}
				for (int k = 0; k < process; k++) {
					if (safe_list[k] == 0) {
						safe_list[k] = i + 1;
						break;
					}
				}
				test();	//�ݹ鴦��
			}
		}
	}
}


int banker() {//���м��㷨
	backup();	//����
	if (allocation() == false) return -1;
	bool flag;
	flag = is_safe();
	if (flag == true) {
		char k;
		printf("\n�Ƿ���䣨y/n��  ");
		scanf("%c", &k);
		if (k == 'y') return 1;
		else {
			re_backup();
			return -1;
		}
	}
	else {
		re_backup();
		return -1;
	}
}
void menu() {	//�˵�����
	printf("\n������ָ��\n");
	printf("\n��ʼ��(init) ��ʾ���ݾ���(show) �жϰ�ȫ��(safe)\n������Դ(request) �ͷ���Դ(release) �˳�(quit)\n����(clear)\n");
	char code[20];
	while (1) {
		printf("\n");
		scanf("%s", code);
		if (_stricmp(code, "init") == 0) {	//���ò���
			zero();
			init();
			init_allocation();
		}
		else if (_stricmp(code, "show") == 0) {	//��ʾ����
			show_me();
		}
		else if (_stricmp(code, "safe") == 0) {	//�жϰ�ȫ��
			is_safe();
		}
		else if (_stricmp(code, "request") == 0) {	//������Դ
			printf("\n�Ƿ�ʹ�����м��㷨��֤��ȫ�ԣ�y/n��\n");
			scanf("%s", code);
			if (_stricmp(code, "y") == 0) banker();
			else allocation();
		}
		else if (_stricmp(code, "release") == 0) {	//�ͷ���Դ
			release();
		}
		else if (_stricmp(code, "quit") == 0) {	//�˳�
			return;
		}
		else if (_stricmp(code, "clear") == 0) {	//����
			system("cls");
			printf("\n������ָ��\n");
			printf("\n��ʼ��(init) ��ʾ���ݾ���(show) �жϰ�ȫ��(safe)\n������Դ(request) �ͷ���Դ(release) �˳�(quit)\n����(clear)\n");
		}
		else printf("������Ч������������\n");
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	/*
	zero();
	init();
	init_allocation();
	show_me();
	is_safe();*/
	menu();
	getchar();
	return 0;
}