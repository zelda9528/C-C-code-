#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
double avg_TurnaroundTime;//ƽ����תʱ��
double AQTT;//ƽ����Ȩ��תʱ��
struct progress {
	char proName[80];
	int arriveTime;//����ʱ��
	int serviceTime;//����ʱ��
	//int flag;		//���ʱ�־��δ����1������0
	int finishTime;//���ʱ��
	int cyclingTime;//��תʱ��
	double float_Wi;//��Ȩ��תʱ��
};

struct progress course[80];
//struct progress course[80]={{0,4},{1,3},{2,5},{3,2},{4,4}};
void health_Examine(int *courseNum)//����Ϸ��Լ��
{
	return;
}

void progressNum(int *courseNum)//������Ŀ
{
	int i = 0;
	for (i = 0; i < *courseNum; i++) {
		printf("�������%d�����̵���Ӧ��Ϣ��\n", i + 1);
		printf("�����������:");
		scanf("%s", course[i].proName);
		printf("�����뵽��ʱ��:");
		scanf("%d", &course[i].arriveTime);
		printf("���������ʱ��:");
		scanf("%d", &course[i].serviceTime);
	}
	return;
}

/*void sort_course(int *courseNum)//�Խ��̰��յ���ʱ���������
{int i=0,j=0;
	struct progress temp=0;
	for(i=0;i<*courseNum-1; i++)
		for(j=i; j<*courseNum; j++){
			if(course[j].arriveTime > course[j+1].arriveTime) {
				temp = course[j];
				course[j] = course[j+1];
				course[j+1] = temp; }}
	return;
}*/


void finish_Time(int *courseNum)//���̵����ʱ��
{
	int i = 0;
	if (course[0].arriveTime != 0)//��һ�����̵�ʱ��
	{
		course[0].finishTime = course[0].arriveTime + course[0].serviceTime;
	}
	course[0].finishTime = course[0].serviceTime;
	for (i = 1; i < *courseNum; i++) {
		if (course[i - 1].finishTime >= course[i].arriveTime) {
			course[i].finishTime = course[i - 1].finishTime + course[i].serviceTime;
		}
		else {
			course[i].finishTime = course[i].arriveTime + course[i].serviceTime;
		}
	}
	return;
}
void cyclingTime(int *courseNum)//��תʱ��
{
	int i = 0;
	for (i = 0; i < *courseNum; i++) {
		course[i].cyclingTime = course[i].finishTime - course[i].arriveTime;
	}
	return;
}

void float_Wi(int *courseNum)//��Ȩ��תʱ��
{
	int i = 0;
	for (i = 0; i < *courseNum; i++) {
		course[i].float_Wi = (double)course[i].cyclingTime / course[i].serviceTime;
	}
	return;
}

void avgTurnaroundTime(int *courseNum)//ƽ����תʱ��
{
	int i = 0, sum_TurnaroundTime = 0;
	for (i = 0; i < *courseNum; i++) {
		sum_TurnaroundTime += course[i].cyclingTime;
	}
	avg_TurnaroundTime = sum_TurnaroundTime / (*courseNum);
	return;
}
void _AQTT(int *courseNum)//ƽ����Ȩ��תʱ��
{
	int i = 0;
	double sum_float_Wi = 0;
	for (i = 0; i < *courseNum; i++) {
		sum_float_Wi += course[i].float_Wi;
	}
	AQTT = sum_float_Wi / (*courseNum);
	return;
}

void print_FIFO(int *courseNum)//���������ص���Ϣ
{
	int i = 0;
	printf("���̵���Ӧ��Ϣ��\n");
	printf("����\t����ʱ��\t����ʱ��\t���ʱ��\t��תʱ��\t��Ȩ��ת\n");//
	for (i = 0; i < *courseNum; i++) {
		//printf("��%�����̵���Ӧ��Ϣ��\n", i+1);
		printf("%s\t    %d\t\t    %d\t\t    %d\t\t   %d\t\t   %.002lf\t\t\n", course[i].proName, course[i].arriveTime, course[i].serviceTime, course[i].finishTime, course[i].cyclingTime, course[i].float_Wi);
		//putchar('\n');
	}
	printf("ƽ����תʱ��\tƽ����Ȩ��תʱ��\n");
	printf("   %.002lf\t\t   %.002lf\n", avg_TurnaroundTime, AQTT);
	return;
}
int main() {
	int courseNum = 5;
	printf("�������������");
	scanf("%d", &courseNum);
	progressNum(&courseNum);//

	//sort_course(&courseNum);//�Խ��̰��յ���ʱ���������
	finish_Time(&courseNum);//���̵����ʱ��
	cyclingTime(&courseNum);//��תʱ��
	float_Wi(&courseNum);//��Ȩ��תʱ��
	avgTurnaroundTime(&courseNum);//ƽ����תʱ��
	_AQTT(&courseNum);//ƽ����Ȩ��תʱ��
	print_FIFO(&courseNum);// 
	return 0;
}
