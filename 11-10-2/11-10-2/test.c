#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int num = 0;//��������ɾ�����ݵĸ���
void Dupl(int * arr,int n)
{
	int i,j,k;
	for (i = 0; i < n-num; i++)//��������е�һ��ֵ
	{
		for (j = i+1; j < n  ; j++)//�жϱ��ֵ�Ƿ����ظ�
		{
			if (arr[i] == arr[j])
			{
				for (k = j; k < n - num - 1; k++)//�����ظ�����������ƽ��
				{
					arr[k] = arr[k + 1];
				}
				j--;
				num++;
				arr[k] = 0;
			}

		}

	}

}
int main()
{
	int arr[1000] = { 0 };
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", arr + i);
	}
	Dupl(arr,n);
	for (int i = 0; i < n-num; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
