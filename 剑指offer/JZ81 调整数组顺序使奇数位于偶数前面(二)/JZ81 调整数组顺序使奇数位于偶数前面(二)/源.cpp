#include"resources.h"

class Solution {
public:
	vector<int> reOrderArrayTwo(vector<int>& array) {
		int size = array.size();
		for (int i = 0, j = size - 1; i < j;)
		{
			if (array[i] % 2 != 0)++i;
			if (array[j] % 2 != 1)--j;
			if (array[i] % 2 == 0 && array[j] % 2 == 1)
			{
				swap(array[i], array[j]);
				++i;
				--j;
			}
		}
		return array;
	}
};


int main(void)
{
	Solution s;
	vector<int> ar{ 1,3,5,6,7 };
	show(s.reOrderArrayTwo(ar));
	return 0;
}