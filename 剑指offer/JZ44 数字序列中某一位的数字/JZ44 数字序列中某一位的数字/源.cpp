#include"resources.h"

class Solution
{
public:
    int findNthDigit(int n) {
        int i = 1, next_level;
        while (true)
        {
            next_level = power_10(i - 1) * i * 9;
            if (n - next_level <= 0)
            {
                int num = (n - 1) / i + power_10(i - 1);
                int r = (n - 1) % i;
                char s[100];
                sprintf(s, "%d", num);
                return s[r]-'0';
            }
            else n -= next_level;
            ++i;
        }
    }
    int power_10(int n)
    {
        int res = 1;
        while (n--)res *= 10;
        return res;
    }
};


int main(void)
{
	Solution s;
    cout << s.findNthDigit(9);
	return 0;
}