#include"resources.h"

class Solution
{
public:
	vector<int> vals;
	void mid_travle(TreeNode* root)
	{
		if (root != nullptr)
		{
			mid_travle(root->left);
			vals.push_back(root->val);
			mid_travle(root->right);
		}
	}
	int KthNode(TreeNode* proot, int k) {
		mid_travle(proot);
		return vals.size() < k || vals.empty() || k == 0 ? -1 : vals[k - 1];
	}
};


int main(void)
{
	Solution s;

	return 0;
}