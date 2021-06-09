#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0;
        int flag = 1;
        int temp_sum;
        ListNode* head = new ListNode(0);//�½�һ���пռ��ͷ�ڵ㣬��ʱ����Բ��������Ƿ���ͷ�ڵ㣬��ֱ��ʹ��head.next
        //���ص�ʱ��Ҳֱ�ӷ���head.next
        ListNode* current = head;
        while (l1 != NULL || l2 != NULL||c!=0)
        {
            if (l1 == NULL&&l2!=NULL)
            {
                temp_sum = l2->val+c;
                l2 = l2->next;
            }
            else if (l2 == NULL&l1!=NULL)
            {
                temp_sum = l1->val+c;
                l1 = l1->next;
            }
            else if (l1 == NULL && l2 == NULL&&c!=0)
            {
                temp_sum = 1;
            }
            else if(l1!=NULL&&l2!=NULL)
            {
                temp_sum = l1->val + l2->val + c;
                l1 = l1->next;
                l2 = l2->next;
            }
            c = temp_sum >= 10 ? 1 : 0;
            current->next= new ListNode(temp_sum % 10);
            current = current->next;
        }
        return head->next;
    }
};

int main(void)
{
    ListNode* head1 = new ListNode(9);
    head1->next = new ListNode(8);
    //head1->next->next = new ListNode(3);
    ListNode* head2 = new ListNode(1);
    //head2->next = new ListNode(6);
    //head2->next->next = new ListNode(4);
    ListNode *ans = Solution().addTwoNumbers(head1, head2);
    while (ans!=NULL)
    {
        cout << ans->val << "->";
        ans = ans->next;
    }
    return 0;
}