#include"resources.h"

class Solution
{
public:
	int InversePairs(vector<int> data) {
		int size = data.size();
		if (size <= 0)return 0;
		else
		{
			int res = 0;
			for (int i = 0; i < size; i++)
			{
				for (int j = i + 1; j < size; j++)
				{
					if (data[i] > data[j])res = ++res % 1000000007;
				}
			}
			return res;
		}
	}
};


int main(void)
{
	Solution s;
	cout << s.InversePairs({ 1,2,3,4,5,6,7,0 });
	return 0;
}