#include"resources.h"

class Solution {
public:
    int rectCover(int number) {
        if (number == 0)return 0;
        else if (number == 1)return 1;
        else if (number == 2)return 2;
        int pre = 1, now = 2, res = 0;
        for (int i = 3; i <= number; ++i)
        {
            res = pre + now;
            pre = now;
            now = res;
        }
        return res;
    }
};


int main(void)
{
	Solution s;

	return 0;
}