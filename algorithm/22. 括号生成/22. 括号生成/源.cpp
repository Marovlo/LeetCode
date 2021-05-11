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
		//回溯法 剪枝条件为：
		//左边括号有剩余时，任何时候都可以添加左边括号
		//只有当右边括号剩余个数大于左边括号时，才可以添加右边括号，
		//注意上两个条件的先后顺序，可以在一次函数调用中既添加左括号也添加右括号
	{
		if (left == 0 && right == 0)
		{
			res.push_back(path);
			return;
		}
		if(left>0)dfs(res, left - 1, right, path + '(');//虽然是大于等于，但是左边剩余实际上不可能大于右边剩余
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