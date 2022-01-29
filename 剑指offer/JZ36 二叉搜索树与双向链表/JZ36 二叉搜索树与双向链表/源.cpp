#include"resources.h"

class Solution
{
public:
	TreeNode* Convert(TreeNode* pRootOfTree) {
		vector<TreeNode*> nodes;
		if (pRootOfTree)
			mid_travel(pRootOfTree, nodes);
		else return pRootOfTree;
		int size = nodes.size();
		for (int i = 0; i < size; ++i)
		{
			if (i != 0)nodes[i]->left = nodes[i - 1];
			else nodes[i]->left == nullptr;
			if (i != size - 1)nodes[i]->right = nodes[i + 1];
			else nodes[i]->right == nullptr;
		}
		return nodes[0];
	}
	void mid_travel(TreeNode* root, vector<TreeNode*>& nodes)
	{
		if (root->left)mid_travel(root->left, nodes);
		nodes.push_back(root);
		if (root->right)mid_travel(root->right, nodes);
	}
};


int main(void)
{
	Solution s;

	return 0;
}