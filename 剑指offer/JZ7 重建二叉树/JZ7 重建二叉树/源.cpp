#include"resources.h"

class Solution
{
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.size() == 0)return nullptr;
		TreeNode* root = new TreeNode(pre[0]);
		rebuild(pre, vin, root);
		return root;
	}
	void rebuild(vector<int>pre, vector<int> vin, TreeNode* root)
	{
		if (pre.size() == 0)return;
		int pos = get_pos(vin, pre[0]);
		vector<int> vin_left(vin.begin(), vin.begin() + pos),
			vin_right(vin.begin() + pos + 1, vin.end());
		vector<int> pre_left(pre.begin() + 1, pre.begin() + vin_left.size() + 1),
			pre_right(pre.begin() + 1 + vin_left.size(), pre.end());
		TreeNode* left = pre_left.size() != 0 ? new TreeNode(pre_left[0]) : nullptr;
		TreeNode* right = pre_right.size() != 0 ? new TreeNode(pre_right[0]) : nullptr;
		root->left = left;
		root->right = right;
		rebuild(pre_left, vin_left, left);
		rebuild(pre_right, vin_right, right);
	}

	int get_pos(const vector<int>& target,int num)
	{
		int size = target.size();
		for (int i = 0; i < size; ++i)
			if (num == target[i])
				return i;
		return 0;
	}
};


int main(void)
{
	Solution s;
	vector<int>pre{ 1 }, vin{ 1 };
	TreeNode* root = s.reConstructBinaryTree(pre, vin);
	return 0;
}