#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
	int n;
	int a[10] = { 0 };
	int i;
	int sum = 0;
	int count = 0;
	for (n = 0; n <= 100000; ++n) { //����0-100000֮����������
		for (i = n; i; i /= 10) {
			a[count] = i % 10;  //������a[count]��ÿһλ������,��count�������ֵ�λ��
			++count;
		}
		for (i = 0; i < count; ++i) {
			sum += pow(a[i], count); //����������������ֵ�ÿһλ���ж�Ӧ��λ��count�η������
		}
		if (n == sum) {
			printf("%d \n", n);
		}
		count = sum = 0; //ǿ�ƽ�count��sum��0
	}
	return 0;
}