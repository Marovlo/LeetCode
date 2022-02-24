#include"resources.h"

class Solution
{
public:
	ListNode* deleteDuplication(ListNode* pHead) {
		ListNode* root = new ListNode(0);
		root->next = pHead;
		ListNode* now = pHead, * pre = root;
		while (now){
			if (now->next && now->val == now->next->val) {
				while (now->next&&now->val==now->next->val){
					now = now->next;
				}
				now = now->next;
			}
			pre->next = now;
			pre = pre->next;
			if (now)now = now->next;
		}
		return root->next;
	}
	ListNode* deleteDuplication_1(ListNode* pHead) {
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