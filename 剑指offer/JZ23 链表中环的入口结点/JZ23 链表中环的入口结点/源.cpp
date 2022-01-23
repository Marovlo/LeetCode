#include"resources.h"

	class Solution
	{
	public:
		ListNode* EntryNodeOfLoop(ListNode* pHead) {
			//����ָ�뷽��,��ָ��ÿ��������,��ָ��ÿ����һ��,��ָ�����ָ���һ��������Ϊp��,��ʹ��ָ��ֱ������������p����
			//����ָ��ÿ�ζ���һ��,���ʱ����ָ��������ʱ�����㼴Ϊ��ڵ�.
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