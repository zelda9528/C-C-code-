#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
struct Stu
{
	char name[20];
	int age;
	float score;
};
int main()
{
	struct Stu s = { 0 };
	FILE* pf = fopen("test.dat", "rb");
	if (pf == NULL)
	{
		perror("open file for reading");
		return 1;
	}
	//���ļ�
	fread(&s, sizeof(struct Stu), 1, pf);
	printf("%s %d %f\n", s.name, s.age, s.score);

	//�ر��ļ�
	fclose(pf);
	pf = NULL;
	return 0;
}