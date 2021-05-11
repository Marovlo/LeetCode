#include<iostream>
using namespace std;

struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
   ListNode* removeNthFromEnd(ListNode* head, int n) {//˫ָ�뷨,Ҳ�п���ָ�룬ʹ��ָ�����ָ���n���ڵ�
      //����ָ��ָ��ĩβ��ʱ����ָ�����һ���ڵ�պ��ǵ�����n���ڵ�
      ListNode* prehead = new ListNode();
      prehead->next = head;
      ListNode* first = head, *second = prehead;
      for (int i = 0; i < n; i++)first = first->next;
      while (first)
      {
         first = first->next;
         second = second->next;
      }
      ListNode* toDelete = second->next;
      second->next = second->next->next;
      ListNode* ans = prehead->next;
      delete toDelete, prehead;
      return ans;
   }
};
