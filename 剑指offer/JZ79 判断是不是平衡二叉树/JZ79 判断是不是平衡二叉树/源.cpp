#include"resources.h"

class Solution
{
public:
	bool IsBalanced_Solution(TreeNode* pRoot) {
		if (pRoot)
		{
			int left_height = get_height(pRoot->left,0);
			int right_height = get_height(pRoot->right,0);
			if ((left_height - right_height) > 1 || (left_height - right_height) < -1)return false;
			else return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
		}
		else return true;
	}

	int get_height(TreeNode* root,int height)
	{
		if (root == nullptr)return 0;
		else if (root->left == nullptr && root->right == nullptr)return height;
		else
		{
			int left_height = get_height(root->left, height + 1);
			int right_height = get_height(root->right, height + 1);
			return left_height > right_height ? left_height : right_height;
		}
	}
};


int main(void)
{
	Solution s;

	return 0;
}