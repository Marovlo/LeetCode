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
         else if (rhigh > low)//分段在右的右边，即左中右都是有序段，即为普通二分查找
         {
            if (target > mid)l = m + 1;
            else r = m - 1;
         }
         else //分段在右的左边，分段点、m两个点将数组分为三份，判断target在哪一份上，并作出相应动作即可
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
   //这里是desktop修改
   //这里是surface修改
   //aaa
}