#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;

class BitSet {
private:
	//��������
	vector<int> _bit;

public:
	//λͼ�Ĵ�С�����ݷ�Χ�йأ������ݸ����޹�
	BitSet(size_t rang) :_bit(rang / 32 + 1)
	{}

	//�洢��Ϣ
	void Set(size_t num)
	{
		//�ȼ���λ�ã� /32  %32
		int idx = num / 32;		//����λ��
		int bitIdx = num % 32;	//bitλ��
		//�Ѷ�Ӧbitλ��1����λ�����
		_bit[idx] |= 1 << bitIdx;
	}

	//������Ϣ
	bool find(size_t num)
	{
		//����λ��
		int idx = num / 32;
		int bitIdx = num % 32;
		//�ٿ�ֵ
		return _bit[idx] >> bitIdx & 1;
	}

	//ɾ����Ϣ
	void Reset(size_t num)
	{
		//����λ��
		int idx = num / 32;
		int bitIdx = num % 32;
		//��Ϊ0: ��1���ƺ�ȡ������λ�����
		_bit[idx] &= (~(1 << bitIdx));
	}

};

void test()
{
	BitSet bit(512);
	bit.Set(1);
	bit.Set(512);
	bit.Set(2);
	bit.Set(64);
	bit.Set(15);

	cout << "1�Ƿ���ڣ�" << bit.find(1) << endl;
	cout << "2�Ƿ���ڣ�" << bit.find(2) << endl;
	cout << "3�Ƿ���ڣ�" << bit.find(3) << endl;
	cout << "512�Ƿ���ڣ�" << bit.find(512) << endl;

	cout << "------------" << endl;
	bit.Reset(512);
	cout << "512�Ƿ���ڣ�" << bit.find(512) << endl;


}


int main()
{
	test();
	return 0;
}