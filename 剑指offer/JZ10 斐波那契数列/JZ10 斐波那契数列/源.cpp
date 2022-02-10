#include"resources.h"

class Solution
{
public:
	int Fibonacci(int n) {
		if (n == 1 || n == 2)return 1;
		else
		{
			int f = 1, s = 1,now=0;
			for (int i = 2; i < n; ++i)
			{
				now = f + s;
				f = s;
				s = now;
			}
			return now;
		}
	}
};


int main(void)
{
	Solution s;

	return 0;
}