#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


//const����ȫ�ֱ������ı���ȫ�ֱ�����


//#define �����
//#define Add(x,y) (x+y)
//int main()
//{
//	int x = 1;
//	int y = 8;
//	int n = 8;
//	int m = 3;
//	int ret=n*Add(x, y)*m;
//	printf("%d ", ret);
//	return 0;
//
//}


//
//int main()
//{
//	int n = 1;
//	if (n == 5)
//		printf("yes ");
//	else
//		printf("no ");
//	return 0;
//}
//


//switch case���ʹ��
//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//
//	switch (day)
//	{
//		case 1:
//		case 2:
//		case 3:
//		case 4:
//		case 5:
//			printf("weekday\n");
//			break;
//		case 6:
//		case 7:
//			printf("weekend\n");
//			break;
//		default:
//			;
//	}
//
//	return 0;
//
//}



//ѭ�����Ӧ��

//#include <stdio.h>
//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		i += 1;
//
//		if (i == 5)
//			continue;
//		printf("%d ", i);
//	}
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		i = i + 1;
//		if (i == 5)
//			continue;
//		printf("%d ", i);
//	}
//	return 0;
//}
//������Ϊ 2 3 4 6 7 8 9 10 11

//forѭ��������Ŀ
//int main()
//{
//	int i = 0;
//	int k = 0;
//	for (i = 0, k = 0; k = 0; i++, k++)
//		k++;
//	return 0;
//}
//Ϊʲô������Ϊʲô��������Ϊʲô������

//do while���Ӧ��
//int main()
//{
//	int i = 10;
//	do 
//	{
//		printf("hehe");
//		
//		i++;
//	} while (i < 12);
//
//
//	return 0;
//}


//ģ���ַ����������м��۵ĳ���
//#include<windows.h>
//int main()
//{
//	char arr1[] = "welcome to my world";
//	char arr2[] = "*******************";
//	int left = 0;
//	int right = sizeof(arr2) - 1;
//	while (left <= right)
//	{
//		Sleep(1000);
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		left++;
//		right--;
//		printf("%s\n", arr2);
//	}
//
//	return 0;
//}



//#include <stdio.h>
//int main()
//{
//	////����1
//	//for (;;)
//	//{
//	//	printf("hehe\n");
//	//}
//	//����2
//	int x, y;
//	for (x = 0, y = 0; x < 2 && y < 5; ++x, y++)
//	{
//		printf("hehe\n");
//	}
//	return 0;
////}
//int Fact(int x)
//{
//	int i = x;
//	for (int i = x; i > 1; i--)
//	{
//		x *=  (i - 1);
//	}
//	return x;
//	/*return x *= (--i);*/
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d\n", Fact(n));
//
//	return 0;
//}

//�ݹ���׳�
//int Fac(int n)
//{
//	if (n <= 1)
//		return 1;
//	else
//		return n * Fac(n - 1);
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d\n", Fac(n));
//	return 0;
//}



//��1��+2��+3��+...+n!
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = 1;
//	int sum = 0;
//	for (int j = 1; j <= n; j++)//n=3
//	{
//		ret = 1;
//		for (int i = 1; i <= j; i++)
//		{
//			ret *= i;
//		}
//		sum = sum + ret;
//	}
//	printf("%d\n", sum);
//	return 0;
//}