#include"resources.h"

class Solution
{
public:
	int maxValue(vector<vector<int> >& grid) {
		int m = grid.size(), n = grid[0].size();
		if (n == 0)return 0;
		int** values = new int*[m];
		for (int i = 0; i < m; ++i)values[i] = new int[n];
		values[0][0] = grid[0][0];
		int left = 0, up = 0;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (i != 0)up = values[i - 1][j];
				else up = 0;
				if (j != 0)left = values[i][j - 1];
				else left = 0;
				values[i][j] = max(left, up) + grid[i][j];
			}
		}
		return values[m - 1][n - 1];
	}
};




int main(void)
{
	Solution s;
	vector<vector<int>> a{ {1,3,1},{1,5,1},{4,2,1} };
	s.maxValue(a);
	return 0;
}