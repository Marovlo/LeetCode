#include"resources.h"

class Solution
{
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int>> res;
		if (!pRoot)return res;
		else
		{
			queue<TreeNode*> upper;
			upper.push(pRoot);
			vector<int> level;
			int size;
			while (!upper.empty())
			{
				
				size = upper.size();
				while (size--)
				{
					TreeNode* t = upper.front();
					level.push_back(t->val);
					if (t->left)upper.push(t->left);
					if (t->right)upper.push(t->right);
					upper.pop();
				}
				res.push_back(level);
				level.clear();
			}
			return res;
		}
	}
};


int main(void)
{
	Solution s;

	return 0;
}