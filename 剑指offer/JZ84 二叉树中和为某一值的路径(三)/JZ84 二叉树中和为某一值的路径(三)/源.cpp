#include"resources.h"

class Solution
{
public:
	int target = 0, res = 0;
	int FindPath(TreeNode* root, int sum) {
		target = sum;
		if (!root)return 0;
		pre_travel(root);
		return res;
	}

	void pre_travel(TreeNode* root)
	{
		pre_find(root, 0);
		if (root->left)pre_travel(root->left);
		if (root->right)pre_travel(root->right);
	}

	void pre_find(TreeNode* root, int sum)
	{
		sum += root->val;
		if (sum == target)res += 1;
		if (root->left)pre_find(root->left, sum);
		if (root->right)pre_find(root->right, sum);
	}
};


int main(void)
{
	Solution s;

	return 0;
}