#include"resources.h"

class Solution
{
public:
	vector<vector<int>> FindPath(TreeNode* root, int expectNumber) {
		vector<vector<int>> res;
		if(root)
			pre_travel(root, res, {}, 0, expectNumber);
		return res;
	}

	void pre_travel(TreeNode* root, vector<vector<int>>& res, vector<int> path, int sum, int expectNumber)
	{
		sum += root->val;
		path.push_back(root->val);
		if (root->left == nullptr && root->right == nullptr)
		{
			if (sum == expectNumber)res.push_back(path);
		}
		else
		{
			if (root->left)pre_travel(root->left, res, path, sum, expectNumber);
			if (root->right)pre_travel(root->right, res, path, sum, expectNumber);
		}
	}
};


int main(void)
{
	Solution s;

	return 0;
}