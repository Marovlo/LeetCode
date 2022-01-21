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
	vector<int> printListFromTailToHead(ListNode* head) {
		return solu3(head);
	}

	vector<int> solu1(ListNode* head)
	{
		stack<int> s;
		while (head != nullptr)
		{
			s.push(head->val);
			head = head->next;
		}
		vector<int>res;
		while (!s.empty())
		{
			res.push_back(s.top());
			s.pop();
		}
		return res;
	}

	vector<int> solu2(ListNode* head)
	{
		ListNode* now = nullptr;
		ListNode* root = new ListNode(0);
		root->next = nullptr;
		while (head != nullptr)
		{
			now = head;
			head = head->next;
			now->next = root->next;
			root->next = now;
		}
		vector<int>res;
		root = root->next;
		while (root)
		{
			res.push_back(root->val);
			root = root->next;
		}
		return res;
	}

	vector<int> solu3(ListNode* head)
	{
		vector<int>res;
		while (head != nullptr)
		{
			res.push_back(head->val);
			head = head->next;
		}
		reverse(res.begin(), res.end());
		return res;
		
	}

};

int main(void)
{
	Solution s;

	return 0;
}