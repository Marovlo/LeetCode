#include"resources.h"

class Solution
{
public:
	bool IsBalanced_Solution(TreeNode* pRoot) {
		if (pRoot)
		{
			int left_height = get_height(pRoot->left);
			int right_height = get_height(pRoot->right);
			if (abs(left_height - right_height) > 1)return false;
			else return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
		}
		else return true;
	}

	int get_height(TreeNode* root)//求树高的函数
	{
		if (!root)return 0;
		int lheight = get_height(root->left);
		int rheight = get_height(root->right);
		return max(lheight, rheight) + 1;
	}
};


int main(void)
{
	Solution s;

	return 0;
}