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

typedef struct small
{
	ListNode* node;
	int pos;
};

class Solution
{
public:
	//�ڱ����ɣ�һ��ϲ�
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode* prehead = new ListNode;
		prehead->next = NULL;
		ListNode* current = prehead;
		int size = lists.size();
		int empty = 0;
		for (int i = 0; i < size; i++)
		{
			if (lists[i] == NULL)++empty;
		}
		while (empty<size)
		{
			small smallest;
			for (int i = 0; i < size; ++i)
			{
				if (lists[i] != NULL)
				{
					smallest.node = lists[i];//��ֵ��ǰ��СΪ��һ����Ϊ�յ�����ĵ�һ��ֵ
					smallest.pos = i;
					break;
				}
			}
			for (int i = 0; i < size; ++i)
			{
				if (lists[i] != NULL && lists[i]->val < smallest.node->val)//ѡ����ǰ��С�ĵ�һ��
				{
					smallest.node = lists[i];
					smallest.pos = i;
				}
			}
			lists[smallest.pos] = lists[smallest.pos]->next;//����ӵ����С�ĵ�һ��ֵ������
			if (lists[smallest.pos] == NULL)++empty;
			current->next = smallest.node;
			current = current->next;
		}
		return prehead->next;
	}

	/*�����ϲ�
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		if (l1 == NULL)return l2;
		else if (l2 == NULL)return l1;
		else
		{
			if (l1->val <= l2->val)
			{
				l1->next = mergeTwoLists(l1->next, l2);
				return l1;
			}
			else
			{
				l2->next = mergeTwoLists(l2->next, l1);
				return l2;
			}
		}
	}
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode* head=NULL;
		int size = lists.size();
		if (size == 0)return head;
		else
		{
			head = lists[0];
			for (int i = 1; i < size; i++)
			{
				head=mergeTwoLists(head, lists[i]);
			}
		}
		return head;
	}
	//*/
};