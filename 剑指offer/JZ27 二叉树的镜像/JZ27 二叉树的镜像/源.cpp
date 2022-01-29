#include"resources.h"

class Solution
{
public:
	TreeNode* temp = nullptr;
	TreeNode* Mirror(TreeNode* pRoot) {
		if(pRoot)mid_travel(pRoot);
		return pRoot;
	}

	void mid_travel(TreeNode* root)
	{
		temp = root->left;
		root->left = root->right;//对每一个节点交换孩子(不只是交换值,而是整个节点交换
		root->right = temp;
		if(root->left)mid_travel(root->left);
		if(root->right)mid_travel(root->right);
	}
};


int main(void)
{
	Solution s;

	return 0;
}