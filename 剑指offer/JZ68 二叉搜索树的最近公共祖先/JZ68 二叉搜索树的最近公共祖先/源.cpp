#include"resources.h"

class Solution
{
public:
	vector<int> midOrder;
	int lowestCommonAncestor(TreeNode* root, int p, int q) {
		mid_travel(root);
		while (root)
		{
			if (p < root->val && q < root->val)root = root->left;
			else if (p > root->val && q > root->val)root = root->right;
			else return root->val;
		}
		return -1;
	}

	void mid_travel(TreeNode* root)
	{
		if (!root)return;
		else
		{
			mid_travel(root->left);
			midOrder.push_back(root->val);
			mid_travel(root->right);
		}
	}
};


int main(void)
{
	Solution s;

	return 0;
}