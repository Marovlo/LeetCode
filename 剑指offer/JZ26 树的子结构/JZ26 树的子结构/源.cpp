#include"resources.h"

class Solution
{
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
		if (pRoot1 == nullptr || pRoot2 == nullptr)return false;
		else
		{
			if (pRoot1->val == pRoot2->val && tree1HasTree2(pRoot1, pRoot2))return true;
			else return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
		}
	}    
	bool tree1HasTree2(TreeNode* pRoot1, TreeNode* pRoot2)
	{	
		if (pRoot1 != nullptr && pRoot2 == nullptr)return true;
		else if (pRoot1 == nullptr && pRoot2 == nullptr)return true;
		else if (pRoot1 == nullptr && pRoot2 != nullptr)return false;
		else
		{
			if (pRoot1->val == pRoot2->val)return tree1HasTree2(pRoot1->left, pRoot2->left) && tree1HasTree2(pRoot1->right, pRoot2->right);
			else return false;
		}
	}
};


int main(void)
{
	Solution s;

	return 0;
}