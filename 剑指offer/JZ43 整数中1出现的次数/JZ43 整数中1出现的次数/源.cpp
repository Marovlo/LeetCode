#include"resources.h"

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n) {
        int res = 0;
        int t;
        for (int i = 1; i <= n; ++i)
        {
            t = i;
            while (t)
            {
                if (t % 10 == 1)++res;
                t /= 10;
            }
        }
        return res;
    }
};


int main(void)
{
	Solution s;
	
	return 0;
}