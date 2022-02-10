#include"resources.h"

class Solution
{
public:
	bool Find(int target, vector<vector<int> > array) {
		int rows = array.size();
		int cols = array[0].size();
		for (int i = 0, j = cols - 1; i < rows && j >= 0;)//从右上角出发，小于则往下走，大于则往右走
		{
			if (array[i][j] > target)--j;//比target大，往左走减小，--j
			else if (array[i][j] < target)++i;//比target小，往下走增大，++i
			else return true;
		}
		return false;
	}
};


int main(void)
{
	Solution s;

	return 0;
}