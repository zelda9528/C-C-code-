#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

//1. ���������������ָ���еĵ�һ��ż��λ��
int Findindex(int n)
{
	//�Ȳ���n�е����������
	int m = 2 * n - 1;    //��n�е�Ԫ�ظ���
	vector<vector<int>> ivv(n, vector<int>(m, 0));
	ivv[0][0] = 1;
	for (int i = 1; i < n; i++)
	{
		ivv[i][0] = ivv[i][2 * i] = 1;    //��һ�к͵�����һ�й̶�Ϊ1
		for (int j = 1; j < 2 * i; j++)
		{
			if (j == 1)    //�ڶ���
				ivv[i][j] = ivv[i - 1][j - 1] + ivv[i - 1][j];
			else if (j == 2 * i - 1)//�����ڶ���
				ivv[i][j] = ivv[i - 1][j - 2] + ivv[i - 1][j - 1];
			else
				ivv[i][j] = ivv[i - 1][j - 2] + ivv[i - 1][j - 1] + ivv[i - 1][j];
		}
	}
	//��ѯ��n�е�ż�����ڵ�λ��
	for (int k = 0; k < m; k++)
	{
		if (ivv[n - 1][k] % 2 == 0)
			return k + 1;
	}
	return -1;
}


int Findindex_1(int n)
{
	if (n <= 2)
		return -1;
	else if (n % 2 == 1)
		return 2;
	else if (n % 4 == 0)
		return 3;
	else
		return 4;
}


int main()
{
	int n, index;
	while (cin >> n)
	{
		index = Findindex(n);
		cout << index << endl;
	}
	return 0;
}


//���������
//class Solution {
//public:
//	/**
//	 * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//	 *
//	 *
//	 * @param pRoot TreeNode��
//	 * @return TreeNode��
//	 */
//	TreeNode* Mirror(TreeNode* pRoot) {
//		// write code here
//		if (pRoot == nullptr)
//			return nullptr;
//		TreeNode* tmp = pRoot->left;
//		pRoot->left = pRoot->right;
//		pRoot->right = tmp;
//		Mirror(pRoot->left);
//		Mirror(pRoot->right);
//		return pRoot;
//	}
//};