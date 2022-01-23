#include"resources.h"

class Solution
{
public:
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		int len1 = getListLength(pHead1), len2 = getListLength(pHead2);
		if (len1 > len2)pHead1 = forwardList(pHead1, len1 - len2);
		else pHead2 = forwardList(pHead2, len2 - len1);
		while (pHead1)
		{
			if (pHead1 == pHead2)return pHead1;
			else
			{
				pHead1 = pHead1->next;
				pHead2 = pHead2->next;
			}
		}
		return nullptr;
	}

	ListNode* forwardList(ListNode* root, int len)
	{
		while (len--)root = root->next;
		return root;
	}

	int getListLength(ListNode* root)
	{
		int i = 0;
		while (root)
		{
			++i;
			root = root->next;
		}
		return i;
	}
};


int main(void)
{
	Solution s;

	return 0;
}