#include"resources.h"

class Solution
{
public:
	bool flag = false;
	bool hasPathSum(TreeNode* root, int sum) {
		if(root)
			pre_travel(root, 0, sum);
		return flag;
	}

	void pre_travel(TreeNode* root, int sum,int target)
	{
		sum += root->val;
		if (root->left == nullptr && root->right == nullptr)
		{
			if (sum == target)
			{
				flag = true;
				return;
			}
		}
		else
		{
			if (root->left)pre_travel(root->left, sum, target);
			if (root->right)pre_travel(root->right, sum, target);
		}
	}
};


int main(void)
{
	Solution s;

	return 0;
}