#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

int main(void)
{
	int input;
	srand((unsigned int)time(NULL));
	printf("****��������Ϸ****\n");
	printf("���ִ�ӣ�*������ִ�ӣ�#\n");
	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("��Ϸ������\n");
			break;
		default:
			printf("�������,���������룡����\n\n");
			break;
		}
	} while (input);
	return 0;
}