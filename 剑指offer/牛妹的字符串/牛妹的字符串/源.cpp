#include"resources.h"

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param s string字符串
     * @param k int整型
     * @return string字符串
     */
    string NS_String(string s, int k) {
        set<char,less<char>> sc;
        int len = s.length();
        if (len <= k)return "";
        for (int i = 0; i < len; ++i)sc.insert(s[i]);
        for (auto i = sc.begin(); i != sc.end(); ++i) {
            char to_delete = *i;
            for (int j = 0; j < len; ++j) {
                if (s[j] == to_delete) {
                    s.erase(s.begin() + j);
                    --j;
                    --len;
                }
            }
        }
        return s;
    }
};

int main(void)
{
	Solution s;
    cout << s.NS_String("caabeefa", 2);
	return 0;
}