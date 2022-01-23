#include"resources.h"

class Solution
{
public:
	RandomListNode* Clone(RandomListNode* pHead) {
		RandomListNode* root = pHead,*new_head=new RandomListNode(0);
		RandomListNode* cur = new_head;
		unordered_map<RandomListNode*, int> pairs;
		int pos = 0;
		while (pHead)
		{
			RandomListNode* new_node = new RandomListNode(pHead->label);
			cur->next = new_node;
			cur = cur->next;
			pairs[pHead] = pos++;
			pHead = pHead->next;
		}
		pairs[nullptr] = -1;
		pHead = root;
		cur = new_head->next;
		RandomListNode* work = nullptr;
		int from = 0, to = 0;
		int distance = 0;
		while (pHead)
		{
			to = pairs[pHead->random];
			if (to != -1)
			{
				distance = to - from;
				if (distance==0)cur->random = cur;
				else if (distance>0)
				{
					work = cur;
					while (distance--)work = work->next;
					cur->random = work;
				}
				else
				{
					work = new_head->next;
					while (to--)work = work->next;
					cur->random = work;
				}
			}
			cur = cur->next;
			pHead = pHead->next;
			from++;
		}
		return new_head->next;
	}
};


int main(void)
{
	Solution s;

	return 0;
}