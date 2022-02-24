#include"resources.h"

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param n int整型
     * @param m long长整型
     * @return long长整型vector
     */
    vector<long> FarmerNN(int n, long long m) {
        vector<long> res(n, 0);
        if (n == 1)return { long(m) };
        long up = 0, down = 0;
        bool dir = true;
        int gap = n - 1;
        long t = m / (n - 1);
        down = t % 2 == 0 ? t / 2 : t / 2 + 1;
        up = t - down;
        dir = down > up ? false : true;
        m %= gap;
        res[0] = down;
        res[gap] = up;
        int mid = down + up;
        for (int i = 1; i < gap; ++i)res[i] = mid;
        if (dir)for (int i = 0; m--; ++i)++res[i];
        else for (int i = n - 1; m--; --i)++res[i];
        return res;
    }
};

int main(void)
{
	Solution s;
    s.FarmerNN(4,6);
	return 0;
}