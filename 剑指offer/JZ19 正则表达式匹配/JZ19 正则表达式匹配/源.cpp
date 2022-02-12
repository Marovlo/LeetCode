#include"resources.h"

class Solution
{
public:
	bool match(string str, string pattern) {
		/*为了方便，使用 ss 代指 str，使用 pp 代指 pattern。
		整理一下题意，对于字符串 p 而言，有三种字符：
		普通字符：需要和 s 中同一位置的字符完全匹配
		'.'：能够匹配 s 中同一位置的任意字符
		'*'：不能够单独使用 '*'，必须和前一个字符同时搭配使用，数据保证了 '*' 能够找到前面一个字符。
		能够匹配 s 中同一位置字符任意次。
		所以本题关键是分析当出现 a* 这种字符时，是匹配 0 个 a、还是 1 个 a、还是 2 个 a ...
		
		本题可以使用动态规划进行求解：
		状态定义：f(i,j) 代表考虑 s 中以 i 为结尾的子串和 p 中的 j 为结尾的子串是否匹配。
		即最终我们要求的结果为 f[n][m] 。
		状态转移：也就是我们要考虑 f(i,j) 如何求得，前面说到了 p 有三种字符，所以这里的状态转移也要分三种情况讨论：
		p[j] 为普通字符：匹配的条件是前面的字符匹配，同时 s 中的第 i 个字符和 p 中的第 j 位相同。 即 f(i,j) = f(i - 1, j - 1) && s[i] == p[j] 。
		p[j] 为 '.'：匹配的条件是前面的字符匹配， s 中的第 i 个字符可以是任意字符。即 f(i,j) = f(i - 1, j - 1) && p[j] == '.'。
		p[j] 为 '*'：读得 p[j - 1] 的字符，例如为字符 a。 然后根据 a* 实际匹配 s 中 a 的个数是 0 个、1 个、2 个 ...
		当匹配为 0 个：f(i,j) = f(i, j - 2)
		当匹配为 1 个：f(i,j) = f(i - 1, j - 2) && (s[i] == p[j - 1] || p[j - 1] == '.')
		当匹配为 2 个：f(i,j) = f(i - 2, j - 2) && ((s[i] == p[j - 1] && s[i - 1] == p[j - 1]) || p[j] == '.')
...		*/
		int m = str.length(), n = pattern.length();
		bool** dp = new bool* [m + 1];
		// 技巧：往原字符头部插入空格，这样得到 char 数组是从 1 开始，而且可以使得 f[0][0] = true，可以将 true 这个结果滚动下去
		str = " " + str;
		pattern = " " + pattern;
		dp[0][0] = true;
		for (int i = 0; i <= m; ++i)dp[i] = new bool[n + 1]{ false };
		for (int i = 0; i <= m; ++i)
		{
			for (int j = 1; j <=n; ++j)
			{
				if (j + 1 < n && pattern[j + 1] == '*')continue;
				else if(i-1>=0&&)
			}
		}
	}
};


int main(void)
{
	Solution s;

	return 0;
}