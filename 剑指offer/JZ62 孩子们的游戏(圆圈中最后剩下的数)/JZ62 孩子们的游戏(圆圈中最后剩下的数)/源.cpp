#include"resources.h"

class Solution {
public:
	int LastRemaining_Solution(int n, int m) {
		if (n == 1)return 0;
		else {
			ListNode* head = new ListNode(0), * pre = head;;
			for (int i = 1; i<n;++i)
			{
				ListNode* cur = new ListNode(i);
				pre->next = cur;
				pre = cur;
			}
			pre->next = head;
			while (pre!=head)
			{
				for (int i = 0; i < m - 1; ++i)
				{
					head = head->next;
					pre = pre->next;
				}
				pre->next = head->next;
				head = head->next;
			}
			return head->val;
		}
	}
};


int main(void)
{
	Solution s;
	cout << s.LastRemaining_Solution(5, 3);
	return 0;
}