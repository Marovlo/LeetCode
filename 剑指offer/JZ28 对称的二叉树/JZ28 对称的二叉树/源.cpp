#include"resources.h"

class Solution
{
public:
	bool isSymmetrical(TreeNode* pRoot) {
		if (!pRoot)return true;
		stack<TreeNode*> nodes;
		nodes.push(pRoot->left);
		nodes.push(pRoot->right);
		while (!nodes.empty())
		{
			TreeNode* left = nodes.top();
			nodes.pop();
			TreeNode* right = nodes.top();
			nodes.pop();
			if (!left && !right)continue;
			if (left == nullptr || right == nullptr)return false;
			if (left->val != right->val)return false;
			nodes.push(left->left);
			nodes.push(right->right);
			nodes.push(left->right);
			nodes.push(right->left);
		}
		return true;
	}
};


int main(void)
{
	Solution s;

	return 0;
}