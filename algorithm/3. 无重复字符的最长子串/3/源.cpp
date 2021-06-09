#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string ans;
        if (s.length() == 0)return 0;
        ans += s[0];
        int slen = s.length();
        int alen;
        int max = 1;
        for (int i = 1; i < slen; i++)
        {
            alen = ans.length();
            for (int j = 0; j < alen; j++)
            {
                if (s[i] == ans[j])
                {
                    max = ans.length() > max ? ans.length() : max;
                    ans.replace(0, j + 1, "");
                    break;
                }
            }
            ans += s[i];
        }
        return ans.length() > max ? ans.length() : max;;
    }
};

int main(void)
{
    string test = "umvejcuuk";
    cout << Solution().lengthOfLongestSubstring(test);
    return 0;
}