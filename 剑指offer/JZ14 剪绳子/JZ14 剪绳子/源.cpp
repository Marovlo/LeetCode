#include"resources.h"

class Solution {
public:
	int cutRope(int number) {
		int sans = 0;
		int ers = 0;
		int yu = 0;
		if (number == 2)return 1;
		sans = number / 3;
		yu = number - 3 * sans;
		if (yu == 1)
		{
			ers = 2;
			--sans;
		}
		else if (yu == 2)ers = 1;
		int res = pow(3, sans);
		return ers == 0 ? res : res * (ers == 2 ? 2 * 2 : 2);
	}
};


int main(void)
{
	Solution s;
	cout << s.cutRope(16);
	return 0;
}