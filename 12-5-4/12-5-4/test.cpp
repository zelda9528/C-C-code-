#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
using namespace std;
int main() {
	int count = 0;//����
	int temp;
	int m = 100;//��Ǯ��
	int a = 1;//1Ԫ��ֵ
	int b = 2;//2Ԫ��ֵ
	int c = 5;//5Ԫ��ֵ
	//a, b, c��ֵ��������10,20,50
	for (int i = 0; i <= m / b; ++i) {
		for (int j = 0; j <= m / c; ++j) {
			temp = m - (b * i + c * j);
			if (temp >= 0 && temp % a == 0) {//ֻҪ2Ԫ��5Ԫ���ܺͼ�����������100,ʣ�µĶ���1Ԫ
				++count;
			}
		}
	}
	cout << "������" << count << "��\n";
	return 0;
}