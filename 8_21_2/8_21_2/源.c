#define _CRT_SECURE_NO_WARNINGS 1

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
void menu()
{
	printf("******************************\n");
	printf("******      1. play     ******\n");
	printf("******      0. exit     ******\n");
	printf("******************************\n");
}

//RAND_MAX = 32767 - rand�������ص���һ��0-32767֮��������
 
void game()
{
	//1. ��������� 1-100 ֮��������
	//C��������һ������������ĺ��� - rand
	//time����
	int guess = 0;
	int ret = rand()%100+1;

	//2. ������
	while (1)
	{
		printf("�������:>");
		scanf("%d", &guess);
		if (guess > ret)
		{
			printf("�´���\n");
		}
		else if (guess < ret)
		{
			printf("��С��\n");
		}
		else
		{
			printf("��ϲ�㣬�¶���\n");
			break;
		}
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));//ʱ�̷����仯������ - �����ϵ�ʱ��һֱ�ڱ仯 -
	do
	{
		//1. ��ӡһ���˵�
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			//��Ϸ���߼�
			game();//��������Ϸ�Ĵ���
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ���������ѡ��!\n");
			break;
		}
	} while (input);
	return 0;
}