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

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode* prehead = new ListNode;
		prehead->next = head;
		ListNode* current = prehead;
		while (current->next!=NULL&&current->next->next!=NULL)
		{
			ListNode* a = current->next, * b = current->next->next;
			a->next = b->next;
			b->next = a;
			current->next = b;
			current = current->next->next;
		}
		return prehead->next;
	}
};