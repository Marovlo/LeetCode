#include"resources.h"

class Solution
{
public:
	enum direction
	{
		right,
		left
	};
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int>> res;
		vector<TreeNode*> upper;
		if(pRoot)upper.push_back(pRoot);
		direction dir = right;
		while (!upper.empty())
		{
			res.push_back(get_level_content(upper,dir));
			dir = dir == right ?  left : right;
			upper = get_next_level(upper);
		}
		return res;
	}

	vector<int> get_level_content(vector<TreeNode*> nodes,direction dir)
	{
		vector<int> cur_res;
		if (dir == right)
		{
			for (int i = 0; i < nodes.size(); ++i)
			{
				cur_res.push_back(nodes[i]->val);
			}
		}
		else
		{
			for (int i = nodes.size() - 1; i >= 0; --i)
			{
				cur_res.push_back(nodes[i]->val);
			}
		}
		return cur_res;
	}
	vector<TreeNode*> get_next_level(vector<TreeNode*> nodes)
	{
		vector<TreeNode*>cur_res;
		for (int i = 0; i < nodes.size(); ++i)
		{
			if (nodes[i]->left)cur_res.push_back(nodes[i]->left);
			if (nodes[i]->right)cur_res.push_back(nodes[i]->right);
		}
		return cur_res;
	}
};


int main(void)
{
	Solution s;
	TreeNode* a = new TreeNode(1);
	TreeNode* b = new TreeNode(2);
	TreeNode* c = new TreeNode(3);
	TreeNode* d = new TreeNode(4);
	TreeNode* e = new TreeNode(5);
	a->left = b;
	a->right = c;
	c->left = d;
	c->right = e;

	s.Print(a);
	return 0;
}