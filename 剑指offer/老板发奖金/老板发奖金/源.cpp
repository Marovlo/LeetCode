#include"resources.h"
class Solution {
public:
    /**
     *
     * @param num_money int整型 奖金的总数,单位为元
     * @return int整型
     */
    int CalulateMethodCount(int num_money) {
        if (num_money == 1)return 1;
        else if (num_money == 2)return 2;
        else if (num_money == 3)return 4;
        int dp[3]{ 1,2,4 };
        num_money -= 3;
        while (num_money--)
        {
            int t = dp[0] + dp[1] + dp[2];
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = t;
        }
        return dp[2];
    }
};


int main(void)
{
	Solution s;
    cout << s.CalulateMethodCount(5);
	return 0;
}