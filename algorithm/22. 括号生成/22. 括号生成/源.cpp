#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	vector<string> generateparenthesis(int n) {
		if (n == 0)return {};
		else if (n == 1)return { "()" };
		else
		{
			vector<string> res;
			dfs(res,n,n,"");
			return res;
		}
		return {};
	}
	void dfs(vector<string>& res, int left, int right, string path)
		//���ݷ� ��֦����Ϊ��
		//���������ʣ��ʱ���κ�ʱ�򶼿�������������
		//ֻ�е��ұ�����ʣ����������������ʱ���ſ�������ұ����ţ�
		//ע���������������Ⱥ�˳�򣬿�����һ�κ��������м����������Ҳ���������
	{
		if (left == 0 && right == 0)
		{
			res.push_back(path);
			return;
		}
		if(left>0)dfs(res, left - 1, right, path + '(');//��Ȼ�Ǵ��ڵ��ڣ��������ʣ��ʵ���ϲ����ܴ����ұ�ʣ��
		if (left < right)dfs(res, left, right - 1, path + ')');
	}
};

int main(void)
{
	Solution s;
	vector<string> res = s.generateparenthesis(8);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << endl;
	}
	return 0;
}