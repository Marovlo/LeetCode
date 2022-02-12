#include"resources.h"

class Solution
{
public:
	int jumpFloorII(int number) {
		int dp[30];
		dp[1] = 1;
		for (int i = 2; i <= number; ++i)
		{
			dp[i] = dp[i - 1] * 2;
		}
		return dp[number];
	}
};


int main(void)
{
	Solution s;
	cout << s.jumpFloorII(4);
	return 0;
}