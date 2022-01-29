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
		root->left = root->right;//��ÿһ���ڵ㽻������(��ֻ�ǽ���ֵ,���������ڵ㽻��
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