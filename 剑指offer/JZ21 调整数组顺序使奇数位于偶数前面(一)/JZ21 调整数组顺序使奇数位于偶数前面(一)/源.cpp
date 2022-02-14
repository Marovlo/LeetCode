#include"resources.h"

class Solution {
public:
	vector<int> reOrderArray(vector<int>& array) {
		int size = array.size();
		vector<int> res(size);
		for (int i = 0; i < size; ++i)if (array[i] % 2 == 1)res.push_back(array[i]);
		for (int i = 0; i < size; ++i)if (array[i] % 2 == 0)res.push_back(array[i]);
		return res;
	}
};


int main(void)
{
	Solution s;
	
	return 0;
}