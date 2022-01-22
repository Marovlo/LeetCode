#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr) {}
};

class Solution
{
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
		ListNode* root = new ListNode(0), * cur = root;
		while (pHead1 && pHead2)
		{
			if (pHead1->val > pHead2->val)
			{
				cur->next = pHead2;
				pHead2 = pHead2->next;
			}
			else
			{
				cur->next = pHead1;
				pHead1 = pHead1->next;
			}
			cur = cur->next;
		}
		while (pHead1)
		{
			cur->next = pHead1;
			pHead1 = pHead1->next;
			cur = cur->next;
		}
		while (pHead2)
		{
			cur->next = pHead2;
			pHead2 = pHead2->next;
			cur = cur->next;
		}
		return root->next;
	}
};


int main(void)
{
	Solution s;

	return 0;
}