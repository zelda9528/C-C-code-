#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

//λͼ
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



template <class T,class Hash1, class Hash2, class Hash3>
class BloomFilter {
private:
	//�ײ��װλͼ
	BitSet _bit;
	size_t _bitCount;	//��¼bitλ�ĸ���
public:
	BloomFilter(size_t num)
		:_bit(5 * num)
		,_bitCount(5 * num)
	{}

	//�洢��Ϣ��ʹ�ö��bitλ
	void set(const T& val)
	{
		Hash1 h1;
		Hash2 h2;
		Hash3 h3;
		int idx1 = h1(val) % _bitCount;
		int idx2 = h2(val) % _bitCount;
		int idx3 = h3(val) % _bitCount;
		//��λͼ�з�װ�Ľӿڽ�������ϣλ�õ�ֵ��1
		_bit.Set(idx1);
		_bit.Set(idx2);
		_bit.Set(idx3);
	}
	 
	//����
	bool find(const T&val)
	{
		Hash1 h1;
		Hash2 h2;
		Hash3 h3;
		int idx1 = h1(val) % _bitCount;
		int idx2 = h2(val) % _bitCount;
		int idx3 = h3(val) % _bitCount;
		//
		if (!_bit.find(idx1))
			return false;
		if (!_bit.find(idx2))
			return false;
		if (!_bit.find(idx3))
			return false;

		return true;//���ܴ���


	}


};

struct HashFun1 {
	size_t operator()(const string & str)
	{
		size_t hash = 0;
		for (const auto &ch : str)
		{
			hash = hash * 131 + ch;
		}
		return hash;
	}
};
struct HashFun2 {
	size_t operator()(const string & str)
	{
		size_t hash = 0;
		for (const auto &ch : str)
		{
			hash = hash * 1313131 + ch;
		}
		return hash;
	}
};
struct HashFun3 {
	size_t operator()(const string & str)
	{
		size_t hash = 0;
		for (const auto &ch : str)
		{
			hash = hash * 65599 + ch;
		}
		return hash;
	}
};

void test()
{
	BloomFilter<string, HashFun1, HashFun2, HashFun3> blm(10);
	string str1 ="1https://editor.csdn.net/md?not_checkout=1&articleId=117413980";
	string str2 ="2https://editor.csdn.net/md?not_checkout=1&articleId=117413980";
	string str3 ="3https://editor.csdn.net/md?not_checkout=1&articleId=117413980";

	blm.set(str1);
	blm.set(str2);
	blm.set(str3);
	string str4 ="4https://editor.csdn.net/md?not_checkout=1&articleId=117413980";

	cout<<"str4������: " << blm.find(str4) << endl;

}

int main()
{
	test();
	return 0;
}