#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//��ӡ�˵�
void menu(void)
{
	printf("*************************\n");
	printf("**1.play*********0.exit**\n");
	printf("*************************\n");
}

//��ʼ������
void InitBoard(char board[ROW][COL], int  row, int col)
{
	int i;
	int j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//��ʾ����
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i;
	int j;
	printf("     ");
	for (j = 0; j < col; j++)
	{
		printf("%2d  ", j + 1);
	}
	printf("\n\n");
	for (i = 0; i < row; i++)
	{
		printf("%3d  ", i + 1);
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n     ");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
		}
		printf("\n");
	}
}

//�������
void PlayerMove(char board[ROW][COL], int row, int col, int arr[])
{
	int i;
	int j;

	printf("���������\n");
	printf("������λ�ã�");
	printf("���磺1 1����λ�ö�Ӧ�������Ͻǵ�һ��,������ϰ�enter��������\n");
	while (1)
	{
		scanf("%d %d", &i, &j);
		if ((i - 1) >= 0 && (i - 1) < row && (j - 1) >= 0 && (j - 1) < row)
		{
			if (board[i - 1][j - 1] == ' ')
			{
				board[i - 1][j - 1] = '*';
				arr[0] = i - 1;
				arr[1] = j - 1;
				return arr;
			}
			else
			{
				printf("��λ���������ӣ����������룡��\n");
			}
		}
		else
		{
			printf("�������겻�����̷�Χ�ڣ����������룡��\n");
		}
	}
}
//��������
void ComMove(char board[ROW][COL], int row, int col, int arr[])
{
	printf("�õ������ӣ�\n");
	int i;
	int j;
	while (1)
	{
		i = rand() % row;
		j = rand() % col;
		if (board[i][j] == ' ')
		{
			board[i][j] = '#';
			arr[0] = i;
			arr[1] = j;
			return arr;
		}
	}
}

//�ж���Ӯ
char Winner(char board[ROW][COL], int row, int col, int arr[])
{
	int i;
	int j;
	int x = arr[0];
	int y = arr[1];
	int count[4] = { 1,1,1,1 };

	//������
	for (i = x + 1; i < row; i++)
	{
		if (board[i][y] == board[x][y] && board[x][y] != ' ')
		{
			(count[0])++;
		}
		else
		{
			break;
		}
	}
	//���Ҽ��
	for (i = x - 1; i >= 0; i--)
	{
		if (board[i][y] == board[x][y] && board[x][y] != ' ')
		{
			(count[0])++;
		}
		else
		{
			break;
		}
	}

	//���ϼ��
	for (j = y + 1; j < col; j++)
	{
		if (board[x][j] == board[x][y] && board[x][y] != ' ')
		{
			(count[1])++;
		}
		else
		{
			break;
		}
	}

	//���¼��
	for (j = y - 1; j >= 0; j--)
	{
		if (board[x][j] == board[x][y] && board[x][y] != ' ')
		{
			(count[1])++;
		}
		else
		{
			break;
		}
	}

	//�����ϼ��
	i = x + 1;
	j = y + 1;
	while (i < row && j < col)
	{
		if (board[i][j] == board[x][y] && board[x][y] != ' ')
		{
			(count[2])++;
			i++;
			j++;
		}
		else
		{
			break;
		}
	}
	//�����¼��
	i = x - 1;
	j = y - 1;
	while (i >= 0 && j >= 0)
	{
		if (board[i][j] == board[x][y] && board[x][y] != ' ')
		{
			(count[2])++;
			i--;
			j--;
		}
		else
		{
			break;
		}
	}

	//�����ϼ��
	i = x - 1;
	j = y + 1;
	while (i >= 0 && j < col)
	{
		if (board[i][j] == board[x][y] && board[x][y] != ' ')
		{
			(count[3])++;
			i--;
			j++;
		}
		else
		{
			break;
		}
	}

	//�����¼��
	i = x + 1;
	j = y - 1;
	while (i < row && j >= 0)
	{
		if (board[i][j] == board[x][y] && board[x][y] != ' ')
		{
			(count[3])++;
			i++;
			j--;
		}
		else
		{
			break;
		}
	}

	for (i = 0; i < 4; i++)
	{
		if (count[i] >= COUNT)
		{
			return board[x][y];
		}
	}

	//�����Ƿ�����
	int ret = IsFull(board, ROW, COL);
	if (ret)
	{
		return 'E';
	}
	return 'C';
}

//�ж������Ƿ�������
int IsFull(char board[ROW][COL], int row, int col)
{
	int i;
	int j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < row; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}



//��Ϸ����
void game(void)
{
	char ret;

	//���ڽ�����������
	int arr[2];

	//��Ϸ���沿��
	//����һ������
	char board[ROW][COL] = { 0 };
	//��ʼ������
	InitBoard(board, ROW, COL);
	//��ӡ����
	DisplayBoard(board, ROW, COL);

	//��Ϸ���ܲ���
	while (1)
	{
		//�������
		PlayerMove(board, ROW, COL, arr);
		DisplayBoard(board, ROW, COL);
		ret = Winner(board, ROW, COL, arr);
		if (ret != 'C')
		{
			break;
		}
		//��������
		ComMove(board, ROW, COL, arr);
		printf("��������λ����:(%d,%d)\n", arr[0] + 1, arr[1] + 1);
		DisplayBoard(board, ROW, COL, arr);
		ret = Winner(board, ROW, COL, arr);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("��ϲ�㣬ʤ����\n");
	}
	else if (ret == '#')
	{
		printf("���ź���ʧ���ˣ�\n");
	}
	else
	{
		printf("����൱�����ƽ��\n");
	}
}