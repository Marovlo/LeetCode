#include"resources.h"

class Solution
{
public:
	vector<int> printNumbers(int n) {
		vector<int>res;
		int limit = power(10, n);
		for (int i = 1; i < limit; ++i)res.push_back(i);
		return res;
	}

	int power(int under,int index)
	{
		int ori = under;
		for (int i = 1; i < index; ++i)under *= ori;
		return under;
	}
};


int main(void)
{
	Solution s;
	s.printNumbers(3);
	return 0;
}