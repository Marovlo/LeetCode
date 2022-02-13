#include"resources.h"

class Solution
{
public:
	int Sum_Solution(int n) {
		bool x = n > 1 && (n += Sum_Solution(n - 1));
		return n;
	}
};


int main(void)
{
	Solution s;
	cout << s.Sum_Solution(3580);
	return 0;
}