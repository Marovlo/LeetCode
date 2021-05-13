#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
   int search(vector<int>& nums, int target) {
      int size = nums.size();
      int l = 0, r = size - 1;
      int m,low,mid,rhigh;
      while (r>l)
      {
         m = (l + r)/2;
         low = nums[l];
         mid = nums[m];
         rhigh = nums[r];
         if (target == mid)return m;
         else if (rhigh > low)//�ֶ����ҵ��ұߣ��������Ҷ�������Σ���Ϊ��ͨ���ֲ���
         {
            if (target > mid)l = m + 1;
            else r = m - 1;
         }
         else //�ֶ����ҵ���ߣ��ֶε㡢m�����㽫�����Ϊ���ݣ��ж�target����һ���ϣ���������Ӧ��������
         {
            if (mid < low)
            {
               if (target > mid && target <= rhigh)l = m + 1;
               else r = m - 1;
            }
            else
            {
               if (target >= low && target < mid)r = m - 1;
               else l = m + 1;
            }
         }
      }
      return nums[l] == target ? l : -1;
   }
};

int main(void)
{
   Solution s;
   vector<int> nums = { 3,5,1 };
   cout<<s.search(nums, 3);
   return 0;
   //������desktop�޸�
   //������surface�޸�
   //aaa
}