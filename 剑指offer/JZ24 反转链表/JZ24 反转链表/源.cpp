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
	ListNode* ReverseList(ListNode* pHead)
	{
		//ͷ�巨
		ListNode* root = new ListNode(0), * now;
		root->next = nullptr;
		while (pHead != nullptr)
		{
			now = pHead;
			pHead = pHead->next;
			now->next = root->next;
			root->next = now;
		}
		return root->next;
	}
};


int main(void)
{
	Solution s;

	return 0;
}