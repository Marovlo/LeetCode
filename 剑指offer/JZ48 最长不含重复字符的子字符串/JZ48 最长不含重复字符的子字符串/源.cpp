#include"resources.h"

class Solution
{
public:
	int lengthOfLongestSubstring(string s) {
		int* buffer = new int[128];
		memset(buffer, -1, sizeof(int) * 128);
		int len = s.length();
		if (len == 0)return 0;
		int* dp = new int[len];
		for (int i = 0; i < len; ++i)dp[i] = 1;
		buffer[s[0]] = 0;
		int distance = 0;
		for (int i = 1; i < len; ++i)
		{
			if (buffer[s[i]] == -1)//没出现过
			{
				dp[i] = dp[i - 1] + 1;
			}
			else
			{
				distance = i - buffer[s[i]];//同一个字符与上次出现相隔的距离
				//选取相隔距离和dp[i-1]+1中小的哪个
				dp[i] = dp[i - 1] + 1 > distance ? distance:dp[i - 1] + 1;
			}
			buffer[s[i]] = i;
		}
		return *max_element(dp, dp + len);
	}
};


int main(void)
{
	Solution s;
	cout << s.lengthOfLongestSubstring("abcabcbb");
	return 0;
}