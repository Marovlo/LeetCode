#include<iostream>
#include<string>
#include<vector>
using namespace std;

int calc(int a, int b, char op)
{
	if (op == 'x')return a * b;
	else if (op == '/')return a / b;
	else if (op == '+')return a + b;
	else return a - b;
}

int main(void)
{
	freopen("in.txt", "r", stdin);
	int n;
	string s;
	for (int j = 0; j < n; ++j)
	{
		cin >> s;
		vector<char> ops{ s[1],s[3],s[5] };
		vector<int> nums{ s[0] - '0', s[2] - '0', s[4] - '0',s[6] - '0' };
		for (int i = 0; i < ops.size(); ++i)
		{
			if (ops[i] == 'x' || ops[i] == '/')
			{
				int res = calc(nums[i], nums[i + 1], ops[i]);
				ops.erase(ops.begin() + i);
				nums.insert(nums.begin() + i, res);
				nums.erase(nums.begin() + i);
				nums.erase(nums.begin() + i + 2);
			}
		}
	}
}