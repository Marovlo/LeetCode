#include"resources.h"

class Solution
{
public:
	vector<int>midOrder;
	int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
		mid_travel(root);
		int pos1, pos2, posRoot, size;
		unordered_map<int, int>poss;
		for (int i = 0; i < midOrder.size(); ++i)poss[midOrder[i]] = i;
		pos1 = poss[o1];
		pos2 = poss[o2];
		while (root)
		{
			posRoot = poss[root->val];
			if (pos1 < posRoot && pos2 < posRoot)root = root->left;
			else if (pos1 > posRoot && pos2 > posRoot)root = root->right;
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