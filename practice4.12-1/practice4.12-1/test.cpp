#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int>st;
		for (const auto&str : tokens)
		{
			if (str == "+" || str == "-" || str == "*" || str == "/")
			{
				//��������
				//��ջ��ȥ����������
				int right = st.top();
				st.pop();
				int left = st.top();
				st.pop();
				//���㣬�������ջ
				if (str == "+")
					st.push(left + right);
				if (str == "-")
					st.push(left - right);
				if (str == "*")
					st.push(left*right);
				if (str == "/")
					st.push(left / right);
			}
			else
				st.push(stoi(str));//��������ջ
		}
		return st.top();
	}
};