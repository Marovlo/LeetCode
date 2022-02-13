#include"resources.h"

	class Solution
	{
	public:
		vector<int> printMatrix(vector<vector<int> > matrix) {
			vector<int>res;
			int rows = matrix.size();
			int cols = matrix[0].size();
			int lx = 0, ly = 0, rx = cols, ry = rows;
			if (rows == 1 && cols == 1)return{ matrix[0][0] };
			while ((rx >= lx + 1 || ry >= ly + 1)&&rx>lx&&ry>ly)
			{
				printLayer(matrix, lx++, ly++, rx--, ry--, res);
			}
			return res;
		}
		void printLayer(vector<vector<int>> matrix,int lx,int ly,int rx,int ry,vector<int>&res)
		{
			for (int i = lx; i < rx; ++i)
				res.push_back(matrix[ly][i]);
			for (int i = ly + 1; i < ry - 1; ++i)res.push_back(matrix[i][rx - 1]);
			if(ry-1!=ly)
				for (int i = rx - 1; i >= lx; --i)res.push_back(matrix[ry - 1][i]);
			if(lx!=rx-1)
				for (int i = ry - 2; i >= ly + 1; --i)res.push_back(matrix[i][lx]);
		}

		void show(vector<int>res)
		{
			int size = res.size();
			for (int i = 0; i < size; ++i)cout << res[i] << " ";
			return;
		}
	};


int main(void)
{
	Solution s;
	vector<vector<int>>a{ {1,2,3} };
	s.show(s.printMatrix(a));
	return 0;
}