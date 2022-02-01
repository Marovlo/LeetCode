#include"resources.h"

class Solution
{
public:
	vector<TreeLinkNode*> nodes;
	TreeLinkNode* GetNext(TreeLinkNode* pNode) {
		TreeLinkNode* temp = pNode;
		TreeLinkNode* root = pNode;
		while (pNode)//找出最前面的根节点
		{
			root = pNode;
			pNode = pNode->next;
		}
		mid_travel(root);
		int size = nodes.size();
		for (int i = 0; i < size; ++i)
		{
			if (nodes[i] == temp)return nodes[i + 1];
		}
		return nullptr;
	}

	void mid_travel(TreeLinkNode* root)
	{
		if (root->left)mid_travel(root->left);
		nodes.push_back(root);
		if (root->right)mid_travel(root->right);
	}
};


int main(void)
{
	Solution s;

	return 0;
}