#include"resources.h"

class Solution
{
public:
	int shopping(int n, int V, vector<int>& ai) {
		sort(ai.begin(), ai.end(), [](int a, int b)->int {return a < b; });
		int res = 0;
		for (int i = 0; i < n; ++i)
		{
			V -= ai[i];
			if (V < 0)break;
			++res;
		}
		return res;
	}
};


int main(void)
{
	Solution s;
	vector<int> ai = { 50,105,200 };
	cout << s.shopping(3, 50, ai);
	return 0;
}