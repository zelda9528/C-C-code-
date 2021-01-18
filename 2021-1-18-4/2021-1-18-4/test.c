#define _CRT_SECURE_NO_WARNINGS 1
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


typedef struct TreeNode* stdatatype;

typedef struct stack {
	stdatatype* data;
	int size;
	int capacity;
}stack;

//��ʼ��
void Initstack(stack* st)
{
	if (st == NULL)
		return;
	st->data = NULL;
	st->capacity = st->size = 0;
}

//�������
void Checkcapacity(stack*st)
{
	if (st->size == st->capacity)
	{
		int newcapacity = st->capacity == 0 ? 1 : 2 * st->capacity;
		st->data = (stdatatype*)realloc(st->data, sizeof(stdatatype)*newcapacity);
		st->capacity = newcapacity;
	}
}

//��ջ
void Stackpush(stack* st, stdatatype val)
{
	if (st == NULL)
		return;
	Checkcapacity(st);
	st->data[st->size++] = val;
}

//��ջ
void Stackpop(stack* st)
{
	if (st == NULL || st->size == 0)
		return;
	st->size--;
}

//��ȡջ��Ԫ�ظ���
int Satcksize(stack* st)
{
	if (st == NULL)
		return 0;
	return st->size;
}

//�ж�ջ��
int Emptystack(stack*st)
{
	if (st == NULL || st->size == 0)
		return 1;
	else
		return 0;
}

//��ȡջ��Ԫ��
stdatatype Stacktop(stack* st)
{
	return st->data[st->size - 1];
}

//����ջ
void Destorystack(stack*st)
{
	free(st->data);
	st->data = NULL;
	st->size = 0;
	st->capacity = 0;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int getsize(struct TreeNode* root)
{
	if (root)
		return getsize(root->left) + getsize(root->right) + 1;
	else
		return 0;
}
int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
	int sz = getsize(root);
	int* arr = malloc(sizeof(int)*sz);
	int idx = 0;
	stack st;
	Initstack(&st);
	//��һ�η��ʵĽ��
	struct TreeNode* prev = NULL;
	while (root || !Emptystack(&st))
	{
		//1.��������·��
		while (root)
		{
			Stackpush(&st, root);
			root = root->left;
		}
		// top : ջ��Ԫ��
		struct TreeNode* top = Stacktop(&st);
		//�ж�ջ��Ԫ���Ƿ���Է���
		//���Է��ʵ������û��������||�������������
		//�������������ָ��һ�η��ʣ�prev���Ľ�����������ĸ����
		if (top->right == NULL || top->right == prev)
		{
			arr[idx++] = top->val;
			Stackpop(&st);
			//����prev
			prev = top;
		}
		else
			//������û�з��ʣ���i��������������
			root = top->right;
	}
	*returnSize = idx;
	return arr;
}