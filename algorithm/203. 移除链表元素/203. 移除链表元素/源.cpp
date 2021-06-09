#include<iostream>
#include<string>
#include<vector>


struct ListNode {
   int val;
   ListNode* next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
   ListNode* removeElements(ListNode* head, int val) {
      if (head = NULL)return head;
      ListNode* prehead = new ListNode();
      ListNode* cur = head;
      ListNode* pre = prehead;
      prehead->next = head;
      while (cur->next!=NULL)
      {
         if (cur->val == val)
         {
            pre->next = cur->next;
            delete cur;
            cur = pre->next;
         }
         else
         {
            cur = cur->next;
            pre = pre->next;
         }
      }
      if (cur->val == val)
      {
         delete cur;
         pre->next = NULL;
      }
      return prehead->next;
   }
};

int main(void)
{
   return 0;
}