#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Score
{
	int english_;
	int math_;
	int com_;
	int clg_;
};
struct student
{
	char name[30];
	int num;
	char sex[20];
	struct Score score;
	struct student *next;
};

struct student *build(int n)//��������
{

	int i;
	struct student *head, *p1, *p2;
	p2 = head = (struct student *)malloc(sizeof(struct student));
	for (i = 0; i < n; i++)
	{
		p1 = (struct student *)malloc(sizeof(struct student));
		p2->next = p1;
		p2 = p1;
	}
	p2->next = NULL;
	p2 = head->next;
	while (p2 != NULL)
	{

		printf("������ѧ��������:");
		scanf("%s", &p2->name);
		printf("������ѧ����ѧ��:");
		scanf("%d", &p2->num);
		printf("������ѧ�����Ա�:");
		scanf("%s", &p2->sex);
		printf("��ֱ�����ѧ����Ӣ���ѧ���Ƶ���C���Գɼ�:");
		scanf("%d%d%d%d", &p2->score.english_, &p2->score.math_, &p2->score.com_, &p2->score.clg_);
		p2 = p2->next;
	}
	return head;
}


void printfs(struct student *head)//ȫ���������
{
	struct student *p2;
	p2 = head->next;
	while (p2 != NULL)
	{
		printf("ѧ��������Ϊ:");
		printf("%s\n", p2->name);
		printf("ѧ����ѧ��Ϊ:");
		printf("%d", p2->num);
		printf("\n���Ա�Ϊ:");
		printf("%s\n", p2->sex);
		printf("ѧ����Ӣ���ѧ���Ƶ���C���Գɼ��ֱ�Ϊ:");
		printf("%d %d %d %d\n", p2->score.english_, p2->score.math_, p2->score.com_, p2->score.clg_);
		printf("\n\n\n");
		p2 = p2->next;
	}
}

void insert2(struct student *head)    //���뺯��
{
	int n = 0;
	struct student *p0, *p1, *p2;
	p0 = (struct student *)malloc(sizeof(struct student));
error1:printf("�������޸ĺ�ѧ��������:");
	scanf("%s", &p0->name);
	printf("ѧ����ѧ��:");
	scanf("%d", &p0->num);
	printf("ѧ�����Ա�:");
	scanf("%s", &p0->sex);
	printf("�ֱ�����ѧ����Ӣ���ѧ���Ƶ���C���Գɼ�:");
	scanf("%d%d%d%d", &p0->score.english_, &p0->score.math_, &p0->score.com_, &p0->score.clg_);

	p2 = head->next;
	while (p2 != NULL)
	{
		if (p0->num == p2->num)
		{
			printf("����Ҫ�����ѧ���Ѵ��ڣ����������룡");
			goto error1;
		}
		p2 = p2->next;
	}

	p2 = head->next;
	p1 = p2->next;
	if (p0->num < p2->num)
	{
		p0->next = p2;
		head->next = p0;

	}
	else
		while (p1 != NULL)
		{
			if (p2->num<p0->num&&p1->num>p0->num)
			{
				p0->next = p1;
				p2->next = p0;
				break;
			}

			p1 = p1->next;
			p2 = p2->next;
		}
	if (p2->next == NULL)
	{
		if (p2->num < p0->num)
		{
			p2->next = p0;
			p0->next = NULL;
		}
	}


}
void sort(struct student *head)//�ɼ�����
{
	struct student *p1, *p2;
	int i = 0, j, t, x, m;
	float n = 0;
	int a[100], b[100];
	p1 = head->next;
	while (p1 != NULL)
	{
		b[i] = p1->score.clg_ + p1->score.com_ + p1->score.english_ + p1->score.math_;
		i++;
		p1 = p1->next;
	}
	for (j = 0; j < i; j++)
		for (x = 0; x < i - x; x++)
			if (b[x] > b[x + 1])
			{
				t = b[x];
				b[x] = b[x + 1];
				b[x + 1] = t;
			}
	printf("ѧ���ܷ�����Ϊ��");
	for (x = 0; x < i; x++)
		printf("%d", b[x]);



	p1 = head->next;
	i = 0;
	while (p1 != NULL)
	{
		a[i] = p1->score.english_;
		i++;
		p1 = p1->next;
	}

	for (m = 0; m < i; m++)
		n += a[m];
	n = n / i;
	for (j = 0; j < i; j++)
		for (x = 0; x < i - x; x++)
			if (a[x] > a[x + 1])
			{
				t = a[x];
				a[x] = a[x + 1];
				a[x + 1] = t;
			}
	printf("Ӣ��ɼ��ӵ͵�������Ϊ:");
	for (x = 0; x < i; x++)
		printf("%d ", a[x]);
	printf("ƽ���ɼ�Ϊ��");
	printf("%.1f", n);
	p2 = head->next;
	while (p2 != NULL)
	{
		if (a[i - 1] == p2->score.english_)
		{
			printf("\n\n\n\tӢ��ɼ���ߵ�ѧ��������Ϊ:");
			printf("%s\n", p2->name);
			printf("\tѧ����ѧ��Ϊ:");
			printf("%d", p2->num);
			printf("\tѧ�����Ա�Ϊ:");
			printf("%s\n", p2->sex);
			printf("\tѧ����Ӣ���ѧ���Ƶ���C���Գɼ��ֱ�Ϊ:");
			printf("%d %d %d %d\n", p2->score.english_, p2->score.math_, p2->score.com_, p2->score.clg_); n++;
		}
		p2 = p2->next;
	}



	i = 0;
	n = 0;
	p1 = head->next;
	while (p1 != NULL)
	{
		a[i] = p1->score.math_;
		i++;
		p1 = p1->next;
	}
	for (m = 0; m < i; m++)
		n += a[m];
	n = n / i;
	for (j = 0; j < i; j++)
		for (x = 0; x < i - x; x++)
			if (a[x] > a[x + 1])
			{
				t = a[x];
				a[x] = a[x + 1];
				a[x + 1] = t;
			}
	printf("\n��ѧ�ɼ��ӵ͵�������Ϊ:");
	for (x = 0; x < i; x++)
		printf("%d ", a[x]);
	printf("ƽ���ɼ�Ϊ��");
	printf("%.1f", n);
	p2 = head->next;
	while (p2 != NULL)
	{
		if (a[i - 1] == p2->score.math_)
		{
			printf("\n\n\n\t��ѧ�ɼ���ߵ�ѧ��������Ϊ:");
			printf("%s\n", p2->name);
			printf("\tѧ����ѧ��Ϊ:");
			printf("%d", p2->num);
			printf("\tѧ�����Ա�Ϊ:");
			printf("%s\n", p2->sex);
			printf("\tѧ����Ӣ���ѧ���Ƶ���C���Գɼ��ֱ�Ϊ:");
			printf("%d %d %d %d\n", p2->score.english_, p2->score.math_, p2->score.com_, p2->score.clg_); n++;
		}
		p2 = p2->next;
	}
	i = 0;
	n = 0;
	p1 = head->next;
	while (p1 != NULL)
	{
		a[i] = p1->score.com_;
		i++;
		p1 = p1->next;
	}
	for (m = 0; m < i; m++)
		n += a[m];
	n = n / i;
	for (j = 0; j < i; j++)
		for (x = 0; x < i - x; x++)
			if (a[x] > a[x + 1])
			{
				t = a[x];
				a[x] = a[x + 1];
				a[x + 1] = t;
			}
	printf("\n��������۳ɼ��ӵ͵�������Ϊ:");
	for (x = 0; x < i; x++)
		printf("%d ", a[x]);
	printf("ƽ���ɼ�Ϊ��");
	printf("%.1f", n);
	p2 = head->next;
	while (p2 != NULL)
	{
		if (a[i - 1] == p2->score.com_)
		{
			printf("\n\n\n\t�Ƶ��ɼ���ߵ�ѧ��������Ϊ:");
			printf("%s\n", p2->name);
			printf("\tѧ����ѧ��Ϊ:");
			printf("%d", p2->num);
			printf("\tѧ�����Ա�Ϊ:");
			printf("%s\n", p2->sex);
			printf("\tѧ����Ӣ���ѧ���Ƶ���C���Գɼ��ֱ�Ϊ:");
			printf("%d %d %d %d\n", p2->score.english_, p2->score.math_, p2->score.com_, p2->score.clg_); n++;
		}
		p2 = p2->next;
	}


	i = 0;
	n = 0;
	p1 = head->next;
	while (p1 != NULL)
	{
		a[i] = p1->score.clg_;
		i++;
		p1 = p1->next;
	}
	for (m = 0; m < i; m++)
		n += a[m];
	n = n / i;
	for (j = 0; j < i; j++)
		for (x = 0; x < i - x; x++)
			if (a[x] > a[x + 1])
			{
				t = a[x];
				a[x] = a[x + 1];
				a[x + 1] = t;
			}
	printf("\nC���Գɼ��ӵ͵�������Ϊ:");
	for (x = 0; x < i; x++)
		printf("%d ", a[x]);
	printf("ƽ���ɼ�Ϊ��");
	printf("%.1f", n);
	p2 = head->next;
	while (p2 != NULL)
	{
		if (a[i - 1] == p2->score.clg_)
		{
			printf("\n\n\n\tC���Գɼ���ߵ�ѧ��������Ϊ:");
			printf("%s\n", p2->name);
			printf("\tѧ����ѧ��Ϊ:");
			printf("%d", p2->num);
			printf("\tѧ�����Ա�Ϊ:");
			printf("%s\n", p2->sex);
			printf("\tѧ����Ӣ���ѧ���Ƶ���C���Գɼ��ֱ�Ϊ:");
			printf("%d %d %d %d\n", p2->score.english_, p2->score.math_, p2->score.com_, p2->score.clg_); n++;
		}
		p2 = p2->next;
	}

}
void find(struct student *head)//����ѧ�Ų��Һ���
{
	int i, n = 0;
	struct student *p2;
	p2 = head->next;
	printf("����������Ҫ���ҵ�ѧ��ѧ��:");
	scanf("%d", &i);
	while (p2 != NULL)
	{
		if (i == p2->num)
		{
			printf("\n\n\n\t����Ҫ���ҵ�ѧ��������Ϊ:");
			printf("%s\n", p2->name);
			printf("\tѧ����ѧ��Ϊ:");
			printf("%d", p2->num);
			printf("\tѧ�����Ա�Ϊ:");
			printf("%s\n", p2->sex);
			printf("\tѧ����Ӣ���ѧ���Ƶ���C���Գɼ��ֱ�Ϊ:");
			printf("%d %d %d %d\n", p2->score.english_, p2->score.math_, p2->score.com_, p2->score.clg_); n++; break;
		}
		p2 = p2->next;
	}
	if (n == 0)
		printf("\t\t���޴��ˣ�");
}
void finds1(struct student *head)//�����������Һ���
{
	char a[30];
	int n = 0;
	struct student *p2;
	printf("������������Ҫ���ҵ�����:");
	scanf("%s", a);
	p2 = head->next;
	while (p2 != NULL)
	{
		if (strcmp(a, p2->name) == 0)
		{
			printf("ѧ��������Ϊ:");
			printf("%s\n", p2->name);
			printf("ѧ����ѧ��Ϊ:");
			printf("%d", p2->num);
			printf("ѧ�����Ա�Ϊ:");
			printf("%s\n", p2->sex);
			printf("ѧ����Ӣ���ѧ���Ƶ���C���Գɼ��ֱ�Ϊ:");
			printf("%d %d %d %d\n", p2->score.english_, p2->score.math_, p2->score.com_, p2->score.clg_); n++;
		}
		p2 = p2->next;
	}
	if (n == 0)
		printf("\t\t���޴��ˣ�");
}
void finds2(struct student *head)//���Ҳ�����ѧ���ɼ�
{
	int n = 0, i = 0;
	struct student *p2, *p0;
	p0 = (struct student *)malloc(sizeof(struct student));
	p2 = head->next;
	while (p2 != NULL)
	{
		if (p2->score.english_ < 60 || p2->score.math_ < 60 || p2->score.com_ < 60 || p2->score.clg_ < 60)
		{
			printf("\n\n\n\t�������ѧ��������Ϊ:");
			printf("%s\n", p2->name);
			printf("\tѧ����ѧ��Ϊ:");
			printf("%d", p2->num);
			printf("\tѧ�����Ա�Ϊ:");
			printf("%s\n", p2->sex);
			printf("\tѧ����Ӣ���ѧ���Ƶ���C���Գɼ��ֱ�Ϊ:");
			printf("%d %d %d %d\n", p2->score.english_, p2->score.math_, p2->score.com_, p2->score.clg_); n++; i++;
		}
		p2 = p2->next;
	}
	printf("\n\t������������ܹ���%d��\n\n", i);
	if (n == 0)
		printf("�޲�����ѧ����");

}




void change(struct student *head)//�޸ĺ���
{
	int i, n = 0;
	struct student *p2;
error:printf("����������Ҫ�޸ĵ�ѧ��ѧ��:");
	scanf("%d", &i);
	p2 = head->next;
	while (p2 != NULL)
	{
		if (i == p2->num)
		{
			printf("ѧ��������Ϊ:");
			printf("%s\n", p2->name);
			printf("ѧ����ѧ��Ϊ:");
			printf("%d", p2->num);
			printf("ѧ�����Ա�Ϊ:");
			printf("%s\n", p2->sex);
			printf("ѧ����Ӣ���ѧ���Ƶ���C���Գɼ��ֱ�Ϊ:");
			printf("%d %d %d %d\n", p2->score.english_, p2->score.math_, p2->score.com_, p2->score.clg_);
			n++;
			break;
		}
		p2 = p2->next;
	}
	if (n == 0)//��δ���ҵ����򱨴�
	{
		printf("���޴��ˣ�");
		goto error;
	}
	printf("�������޸ĺ�ѧ��������:");
	scanf("%s", &p2->name);
	printf("ѧ����ѧ��:");
	scanf("%d", &p2->num);
	printf("ѧ�����Ա�:");
	scanf("%s", &p2->sex);
	printf("�ֱ�����ѧ����Ӣ���ѧ���Ƶ���C���Գɼ�:");
	scanf("%d%d%d%d", &p2->score.english_, &p2->score.math_, &p2->score.com_, &p2->score.clg_);

}
void deletes(struct student *head)//ɾ������

{
	int n;
	struct student *p2, *p1;
	printf("����������Ҫɾ���˵�ѧ��\n");
	scanf("%d", &n);
	p1 = head;
	p2 = head->next;
	while (p2 != NULL)
	{
		if (n == p2->num)
		{
			p1->next = p2->next;
			break;
		}
		p1 = p1->next;
		p2 = p2->next;
	}

}


int main()
{
	int n, i;
	struct student * head;

	printf(" **************************************************************************************************\n");
	printf("  ************************************************************************************************ \n");
	printf("*   ***********************************�ص���ѧ��֪���೤**************************************** *\n");
	printf("*    *******************************************************************************************  *\n");
	printf("*     *****************************************************************************************   *\n");
	printf("*              **********************************************************************             *\n");
	printf("*              *           -------------------------------------------              *             *\n");
	printf("*              *           |         ������ѧ������ϵͳ              |              *             *\n");
	printf("*              *            ------------------------------------------              *             *\n");
	printf("*              *                                                                    *             *\n");
	printf("*              **********************************************************************             *\n");
	printf("*    *******************************************************************************************\n");
	printf("*   *********************************************************************************************\n");
	printf("*   ****              �ҳϽ�ȡ                  &&                  ��������             *******\n");
	printf("* ************************************************************************************************\n");
	printf(" **************************************************************************************************\n");
	printf("\n");
	printf(" �봴��ѧ����Ϣ\n");
	printf("\n");
	printf(" ��������Ҫ������ѧ������:");
	scanf("%d", &n);
	head = build(n);
	printf("\n\n�����ɹ�,�����������������");
	while (getchar() != '\n');
	getchar();
	system("cls");
star:printf("\n\n\t\tѧ����������ϵͳ");
	printf("\n\n\t----------------------------------------");
	printf("\n\n\t\t1������ѧ����Ϣϵͳ");
	printf("\n\n\t\t2���޸�ѧ����Ϣϵͳ");
	printf("\n\n\t\t3������ѧ����Ϣϵͳ");
	printf("\n\n\t\t4��ɾ��ѧ����Ϣϵͳ");
	printf("\n\n\t\t5�����ѧ����Ϣϵͳ");
	printf("\n\n\t\t6��ѧ���ɼ�����ϵͳ");
	printf("\n\n\t\t0���˳�ϵͳ");
	printf("\n\n\t----------------------------------------");
	printf("\n\n��ѡ����Ҫ�ķ��񣨰�����1~6���룩��");
	while (i)
	{
		printf("\n\n\n");
		scanf("%d", &i);
		system("cls");
		switch (i)
		{
		case 1:
			printf("\t1,��ѧ�Ų�ѯ\n");
			printf("\t2,��������ѯ\n");
			printf("\t3,���Ҳ�����ѧ����Ϣ\n\n");
			printf("\t��ѡ��������Ҫ��ѯ�ķ�ʽ\n");
			printf("������1��2��ѡ��������Ҫ�ķ�ʽ:");
			scanf("%d", &n);
			if (n == 1)
				find(head);
			if (n == 2)
				finds1(head);
			if (n == 3)
				finds2(head);
			printf("\n\n�����������ַ�����"); break;
		case 2:change(head); printf("�޸ĳɹ���\n\n"); printf("\n\n�����������ַ�����"); break;
		case 3:	insert2(head);
			printf("������ɣ�\n\n");
			printf("\n\n�����������ַ�����");
			break;
		case 4:deletes(head); printf("ɾ���ɹ���\n\n"); printf("\n\n�����������ַ�����"); break;
		case 5:printfs(head); printf("\n\n�����������ַ�����"); break;
		case 6:sort(head); break;
		case 0:printf("лл����ʹ�ã��������˳���лл��"); break;
		default:printf("����������������룡");
		}
		while (getchar() != '\n');
		getchar();
		system("cls");
		goto star;
		return;
	}
}