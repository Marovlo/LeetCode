#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}

};

typedef struct mylist
{
	ListNode* head, * end;
};

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (k == 1)return head;
		else
		{
			ListNode* prehead = new ListNode;
			prehead->next = head;
			ListNode* cur_head = prehead, * end_next = NULL, * work = head;
			while (true)
			{
				for (int i = 0; i < k - 1; i++)
				{
					if (work == NULL)return prehead->next;
					work = work->next;
				}
				if (work == NULL)return prehead->next;
				end_next = work->next;
				work->next = NULL;
				mylist temp = reverseList(cur_head->next);
				cur_head->next = temp.head;
				temp.end->next = end_next;
				cur_head = temp.end;
				work = end_next;
			}
		}
	}

	mylist reverseList(ListNode* head)
	{
		ListNode* dummy = new ListNode;
		dummy->next = head;
		ListNode *pre = head,*cur=head->next;
		while (cur!=NULL)
		{
			pre->next = cur->next;
			cur->next = dummy->next;
			dummy->next = cur;
			cur = pre->next;
		}
		mylist res;
		res.head = dummy->next;
		res.end = pre;
		return res;
	}
};

ListNode* listProducer(vector<int> origin)
{
	ListNode* head = new ListNode, * cur = head;
	cur->next = NULL;
	int size = origin.size();
	for (int i = 0; i < size; ++i)
	{
		cur->next = new ListNode(origin[i]);
		cur = cur->next;
	}
	return head->next;
}

int main(void)
{
	vector<int> ori = { 1,2,3,4,5,6,7,8 };
	Solution s;
	ListNode* head = s.reverseKGroup(listProducer(ori),3);
	while (head!=NULL)
	{
		cout << head->val << " ";
		head = head->next;
	}
	return 0;
}