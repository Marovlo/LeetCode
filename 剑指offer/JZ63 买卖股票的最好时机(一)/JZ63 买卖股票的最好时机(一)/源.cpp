#include"resources.h"

class Solution
{
public:
	int maxProfit(vector<int>& prices) {
		int his_min = INT_MAX;
		int max_profit = INT_MIN;
		int size = prices.size();
		for (int i = 0; i < size; ++i)
		{
			if (prices[i] < his_min)his_min = prices[i];
			if (prices[i] - his_min > max_profit)max_profit = prices[i] - his_min;
		}
		return max_profit;
	}
};


int main(void)
{
	Solution s;
	vector<int>p = { 8,9,2,5,4,7,1 };
	cout << s.maxProfit(p);
	return 0;
}