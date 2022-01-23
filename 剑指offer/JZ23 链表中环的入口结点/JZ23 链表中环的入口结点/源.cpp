#include"resources.h"

	class Solution
	{
	public:
		ListNode* EntryNodeOfLoop(ListNode* pHead) {
			//快慢指针方法,快指针每次走两步,慢指针每次走一步,快指针和慢指针第一次相遇点为p点,再使两指针分别从起点和相遇点p出发
			//两个指针每次都走一步,则此时两个指针再相遇时所处点即为入口点.
			if (!pHead)return nullptr;
			ListNode* slow = pHead->next;
			if (!slow)return nullptr;
			ListNode* fast = slow->next;
			if (!fast)return nullptr;
			while (slow != fast)
			{
				fast = fast->next;
				if (fast == nullptr)return nullptr;
				fast = fast->next;
				if (fast == nullptr)return nullptr;
				slow = slow->next;
			}
			slow = pHead;
			while (fast != slow)
			{
				fast = fast->next;
				slow = slow->next;
			}
			return fast;
			{

			}
		}
	};


int main(void)
{
	Solution s;

	return 0;
}