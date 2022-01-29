#include"resources.h"

class Solution
{
public:
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		queue<TreeNode*> upper;
		vector<int> res;
		TreeNode* now;
		if (root)upper.push(root);
		while (!upper.empty())
		{
			now = upper.back();
			res.push_back(now->val);
			upper.pop();
			if(now->left)upper.push(now->left);
			if (now->right)upper.push(now->right);
		}
		return res;
	}
};


int main(void)
{
	Solution s;

	return 0;
}