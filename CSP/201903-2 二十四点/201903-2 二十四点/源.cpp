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
	//freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	string s;
	for (int j = 0; j < n; ++j)
	{
		cin >> s;
		vector<char> ops{ s[1],s[3],s[5] };
		vector<int> nums{ s[0] - '0', s[2] - '0', s[4] - '0',s[6] - '0' };
		bool has_pri = true;
		while (has_pri)
		{
			has_pri = false;
			for (int i = 0; i < ops.size(); ++i)
			{
				if (ops[i] == 'x' || ops[i] == '/')
				{
					has_pri = true;
					int res = calc(nums[i], nums[i + 1], ops[i]);
					ops.erase(ops.begin() + i);
					nums.insert(nums.begin() + i + 1, res);
					nums.erase(nums.begin() + i + 2);//先删后面再删前面，防止下标改变导致越界
					nums.erase(nums.begin() + i);
					break;
				}
			}
		}
		while (ops.size()!=0)
		{
			int res = calc(nums[0], nums[1], ops[0]);
			ops.erase(ops.begin());
			nums.insert(nums.begin() + 1, res);
			nums.erase(nums.begin() + 2);
			nums.erase(nums.begin());
		}
		if (nums[0] == 24)cout << "Yes\n";
		else cout << "No\n";
	}
}