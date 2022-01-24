#include"resources.h"

class Solution
{
public:
	ListNode* deleteNode(ListNode* head, int val) {
		if (!head)return head;
		else if (head->val == val)return head->next;
		else
		{
			ListNode* pre = head, * cur = head->next;
			while (cur)
			{
				if (cur->val == val)
				{
					pre->next = cur->next;
					cur = cur->next;
					break;
				}
				cur = cur->next;
				pre = pre->next;
			}
		}
		return head;
	}
};


int main(void)
{
	Solution s;

	return 0;
}