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
   ListNode* removeNthFromEnd(ListNode* head, int n) {//双指针法,也叫快慢指针，使快指针比慢指针快n个节点
      //当快指针指到末尾的时候，慢指针的下一个节点刚好是倒数第n个节点
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
