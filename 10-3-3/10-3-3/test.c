
#include<stdio.h>
int main()
{
	int murder[4] = { 0 }; //Ĭ��4���˶���������

	int i;
	for (i = 0; i < 4; i++) //���������ĸ����е�ĳ����������
	{
		murder[i] = 1; //����ĳ����������
		if ((murder[0] != 1) +
			(murder[2] == 1) +
			(murder[3] == 1) +
			(murder[3] != 1) == 3)
		{
			break; //����ʹ���������ˣ�
		}
		murder[i] = 0; //�����㻹�����
	}

	putchar('A' + i); //��ӡ���ֵı�š����ǵı����0 1 2 3������'A'����A B C D��
	return 0;
}