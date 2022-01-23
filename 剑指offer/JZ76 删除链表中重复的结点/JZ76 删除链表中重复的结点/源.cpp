#include"resources.h"

class Solution
{
public:
	ListNode* deleteDuplication(ListNode* pHead) {
		ListNode* l = nullptr, *m = nullptr, *r = nullptr;
		bool flag = false;
		do {
			flag = false;
			if (!pHead)return pHead;
			while (pHead->next)
			{
				if (pHead->val == pHead->next->val)
				{
					flag = true;
					pHead = pHead->next;
				}
				else break;
			}
			if (flag)pHead = pHead->next;
		} while (flag);
		l = pHead, m = l ? l->next : nullptr, r = m ? m->next : nullptr;
		while (r)
		{
			if (m->val == r->val)
			{
				while (m->val == r->val && r)
				{
					m = m->next;
					r = r->next;
				}
				if (!r)l->next = nullptr;
				else
				{
					m = m->next;
					r = r->next;
					l->next = m;
				}
			}
			else
			{
				l = l->next;
				m = m->next;
				r = r->next;
			}
		}
		return pHead;
	}
};


int main(void)
{
	Solution s;

	return 0;
}