#include"resources.h"

class Solution
{
public:
	int solve(string nums) {
		int dp[100];
		int len = nums.length();
		if (len == 0 || nums[0] == '0')return 0;
		else if (len == 1)return 1;
		else
		{
			dp[0] = 1;
			int code = (nums[0] - '0') * 10 + nums[1] - '0';
			if (code > 10 && code <= 26)dp[1] = 2;
			else dp[1] = 1;
			for (int i = 2; i < len; ++i)
			{
				code = (nums[i - 1] - '0') * 10 + (nums[i] - '0');
				if (code == 10 || code == 20)dp[i] = dp[i - 2];
				else if (code > 10 && code <= 26)dp[i] = dp[i - 1] + dp[i - 2];
				else if (code % 10 == 0)return 0;
				else dp[i] = dp[i - 1];
			}
			return dp[len - 1];
		}
	}
};


int main(void)
{
	Solution s;
	cout << s.solve("72910721221427251718216239162221131917242");
	return 0;
}