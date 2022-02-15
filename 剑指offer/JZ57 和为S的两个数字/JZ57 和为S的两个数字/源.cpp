#include"resources.h"

class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		int size = array.size();
		if (size <= 1)return {};
		int i = 0, j = size - 1;
		int now = 0;
		while (i != j)
		{
			now = array[i] + array[j];
			if (now == sum)return { array[i],array[j] };
			else if (now < sum)++i;
			else --j;
		}
		return {};
	}
};


int main(void)
{
	Solution s;
	show(s.FindNumbersWithSum({ 1,4,4,9 }, 8));
	return 0;
}