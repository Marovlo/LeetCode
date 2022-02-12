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
			if (buffer[s[i]] == -1)//û���ֹ�
			{
				dp[i] = dp[i - 1] + 1;
			}
			else
			{
				distance = i - buffer[s[i]];//ͬһ���ַ����ϴγ�������ľ���
				//ѡȡ��������dp[i-1]+1��С���ĸ�
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