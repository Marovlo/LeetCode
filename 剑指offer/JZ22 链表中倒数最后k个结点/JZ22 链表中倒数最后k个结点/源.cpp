#include"resources.h"

class Solution
{
public:
	ListNode* FindKthToTail(ListNode* pHead, int k) {
		ListNode* latter = pHead;
		int temp = k;
		while (temp--)
		{
			if (latter != nullptr)latter = latter->next;
			else return nullptr;
		}
		while (latter)
		{
			latter = latter->next;
			pHead = pHead->next;
		}
		return pHead;
	}
};


int main(void)
{
	Solution s;

	return 0;
}