#include"resources.h"

class Solution
{
public:
	int  NumberOf1(int n) {
		int t = 0x00000001;
		int res = 0;
		for (int i = 0; i < 32; ++i)
		{
			int p = t & n;x
			if ((t&n)!= 0)
			{
				++res;
			}
			t <<= 1;
		}
		return res;
	}
};


int main(void)
{
	Solution s;
	cout << s.NumberOf1(10);
	return 0;
}