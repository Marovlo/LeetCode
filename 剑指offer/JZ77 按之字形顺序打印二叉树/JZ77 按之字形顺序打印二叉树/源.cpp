#include"resources.h"

class Solution
{
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		bool flag = true;
		vector<vector<int>> res;
		vector<TreeNode*>upper;
		upper.push_back(pRoot);
		enum direction
		{
			right,
			left
		};
		direction dir = right;

		while (flag)
		{
			flag = false;
			vector<int> level;
			if (dir == left)
			{
				for (auto i = upper.rbegin(); i != upper.rend(); ++i)
				{

				}
			}
		}
	}
};


int main(void)
{
	Solution s;

	return 0;
}