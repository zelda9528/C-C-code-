#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>

void left_move(char * src, int k)
{
	int len = strlen(src);
	int pos = k % len; //�Ͽ�λ�õ��±�
	char tmp[256] = { 0 }; //��׼ȷ�Ļ�����ѡ��malloc len + 1���ֽڵĿռ��������tmp

	strcpy(tmp, src + pos); //�Ƚ������ȫ��������
	strncat(tmp, src, pos); //Ȼ��ǰ�漸������
	strcpy(src, tmp); //��󿽻�ȥ
}
int main()
{
	int k = 0;
	scanf("%d", &k);
	char arr[] = "abcdef";
	printf("%s\n", arr);
	left_move(arr, k);
	printf("%s\n", arr);
	return 0;
}