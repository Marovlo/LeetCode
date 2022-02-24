#include"resources.h"

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		vector<int> vec1, vec2;
		get_vector(l1, vec1);
		get_vector(l2, vec2);
		int len1 = vec1.size(), len2 = vec2.size();
		int small = len1 > len2 ? len2 : len1;
		int sum = 0, carry = 0;
		vector<int>res;
		for (auto i = vec1.begin(), j = vec2.begin(); small--; ++i, ++j)
		{
			sum = *i + *j + carry;
			carry = sum >= 10 ? 1 : 0;
			sum %= 10;
			res.push_back(sum);
		}
		vector<int>& conti = len1 < len2 ? vec2 : vec1;
		small = len1 > len2 ? len2 : len1;
		for (auto i = conti.begin() + small; i != conti.end(); ++i)
		{
			sum = *i + carry;
			carry = sum >= 10 ? 1 : 0;
			sum %= 10;
			res.push_back(sum);
		}
		if (carry)res.push_back(1);
		ListNode* root = new ListNode(1);
		ListNode* pre = root, *cur = nullptr;
		for (auto i = res.begin(); i != res.end(); ++i)
		{
			cur = new ListNode(*i);
			pre->next = cur;
			pre = pre->next;
		}
		return root->next;
	}
	vector<int>& get_vector(ListNode* root,vector<int>& res){
		while (root){
			res.push_back(root->val);
			root = root->next;
		}
		return res;
	}
};

ListNode* create(vector<int> data)
{
	ListNode* root = new ListNode(1);
	ListNode* pre = root, * cur = nullptr;
	for (int i = 0; i < data.size(); ++i)
	{
		cur = new ListNode(data[i]);
		pre->next = cur;
		pre = pre->next;
		cur->next = nullptr;
	}
	return root->next;
}


int main(void)
{
	Solution s;
	
	return 0;
}