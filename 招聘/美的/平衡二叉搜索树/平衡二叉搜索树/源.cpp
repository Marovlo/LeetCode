#include"resources.h"
#define SEC_IN_YEAR (365*24*60*60)

	class Solution
	{
	public:
		TreeNode* sortedList2BST(ListNode* head) {
			vector<int> data;
			while (head)
			{
				data.push_back(head->val);
				head = head->next;
			}
			int mid_pos = (0 + data.size()) / 2;
			TreeNode* root = new TreeNode(data[mid_pos]);
			build(root, data, 0, mid_pos, data.size());
			return root;
		}

		void build(TreeNode* root, const vector<int>& data, int left, int mid, int right)
		{
			int left_pos = (left + mid) / 2;
			int right_pos = (right + mid) / 2;
			TreeNode* new_left = new TreeNode(data[left_pos]);
			TreeNode* new_right = new TreeNode(data[right_pos]);
			if (root->val != new_left->val&&left_pos!=0)
			{
				root->left = new_left;
				build(new_left, data, left, left_pos, mid);
			}
			else delete new_left;
			if (root->val != new_right->val)
			{
				root->right = new_right;
				build(new_right, data, mid, right_pos, right);
			}
			else delete new_right;
		}
	};


int main(void)
{
	Solution s;
	ListNode* a = new ListNode(-1);
	ListNode* b = new ListNode(0);
	ListNode* c = new ListNode(1);
	ListNode* d = new ListNode(2);
	ListNode* e = new ListNode(3);
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;
	e->next = nullptr;
	TreeNode* root= s.sortedList2BST(a);
	root;
	return 0;
}