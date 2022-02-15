#include"resources.h"

class Solution {
public:
    long long cutRope(long long number) {
        long long sans = 0;
        long long ers = 0;
        long long yu = 0;
        if (number == 2)return 1;
        if (number == 3)return 2;
        sans = number / 3;
        yu = number - 3 * sans;
        if (yu == 1)
        {
            ers = 2;
            --sans;
        }
        else if (yu == 2)ers = 1;
        long long res = 1, x = 3;
        int mod = 998244353;
        while (sans)
        {
            if (sans & 1)res = (res * x) % mod;
            x = (x * x) % mod;
            sans >>= 1;
        }
        if (ers == 0)return res;
        else
        {
            if (ers == 2)res = (res * 4) % mod;
            else res = (res * 2) % mod;
            return res;
        }
    }
};


int main(void)
{
	Solution s;
    cout << s.cutRope(9696969696968);
	return 0;
}