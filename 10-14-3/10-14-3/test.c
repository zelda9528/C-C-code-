#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//void LeftHanded(char* arr,int time)
//{
//	int i, j, tmp;
//	int len = strlen(arr);
//	time %= len;
//	for ( i = 0; i < time; i++)
//	{
//		tmp = arr[0];
//		for (j = 0; j < len - 1; j++)
//		{
//			arr[j] = arr[j + 1];
//		}
//		arr[j] = tmp;
//		i++;
//	}
//
//
//
//}
//int main()
//{
//	char arr[4] = {'a','b','c','d'};
//	
//	int time = 2;
//	LeftHanded(arr, time);
//
//	for (int j = 0; j < 4; j++)
//	{
//		printf("%c", arr[j]);
//	}
//	return 0;
//}


void leftRound(char * src, int time)
{
	int i, j, tmp;
	int len = strlen(src);
	time %= len; //����Ϊ5������£���ת6��11��16...���൱��1�Σ�7��12��17...���൱��2�Σ��Դ����ơ�
	for (i = 0; i < time; i++) //ִ��k�εĵ���ƽ��
	{
		tmp = src[0];
		for (j = 0; j < len - 1; j++) //����ƽ��
		{
			src[j] = src[j + 1];
		}
		src[j] = tmp;
	}
}
int main()
{
	char src[] = { 'a','b','c','d' };
	int time = 2;
	leftRound(src, time);
	for (int j = 0; j < 4; j++)
			{
				printf("%c", src[j]);
			}
	return 0;
}