#include"resources.h"

class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param s string�ַ���
     * @param k int����
     * @return string�ַ���
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