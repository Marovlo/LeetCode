#include"resources.h"

class Solution
{
public:
	static bool cmp(int a, int b) { return a < b; }
	bool IsContinuous(vector<int> numbers) {
		int zeros = 0;
		int min = 14;
		vector<bool>ar(14, false);
		for (int i = 0; i < 5; ++i)
		{
			if (numbers[i] == 0)++zeros;
			else if (ar[numbers[i]] == true)return false;
			else
			{
				ar[numbers[i]] = true;
				if (numbers[i] < min)min = numbers[i];
			}
		}
		for (int i = min; i < min + 5; ++i)
		{
			if (ar[i] == true)continue;
			else
			{
				if (zeros-- != 0)continue;
				else return false;
			}
		}
		return true;
	}
};


int main(void)
{
	Solution s;
	cout << atoi("5+10");
	return 0;
}