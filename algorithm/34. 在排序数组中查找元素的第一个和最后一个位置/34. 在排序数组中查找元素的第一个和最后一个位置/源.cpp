#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
   vector<int> searchRange(vector<int>& nums, int target) {
      int l = 0, r = nums.size() - 1, m = 0;
      if (r == -1)return { -1,-1 };
      else if (r == 0)
      {
         if (nums[0] == target)return { 0,0 };
         else return { -1,-1 };
      }
      int mid_pos = -1;
      while (l<r)
      {
         m = (l + r) / 2;
         if (target == nums[m])
         {
            mid_pos = m;
            break;
         }
         else if (target < nums[m])r = m - 1;
         else l = m + 1;
      }
      if (r == -1 || l == nums.size())return { -1,-1 };
      if (nums[l] == target)mid_pos = l;
      else if (nums[r] == target)mid_pos == r;
      if (mid_pos == -1)return{ -1,-1 };
      else
      {
         int left = last_pos(nums, 0, mid_pos, target,1);
         int right = last_pos(nums, mid_pos, nums.size() - 1, target,0);
         return { left,right };
      }
   }
   int last_pos(vector<int>& nums, int l, int r, int target,int direction)
   {
      int m;
      while (l < r)
      {
         m = (l + r) / 2;
         if (nums[l] == target)
         {
            if (nums[m] == target)l = m + 1;
            else r = m - 1;
            if (nums[l] != target)return m;
         }
         else
         {
            if (nums[m] == target)r = m - 1;
            else l = m + 1;
            if (nums[r] != target)return m;
         }
         if (direction && nums[l] == target)return l;
         else if (!direction && nums[r] == target)return r;
      }
      return l;
   }
};

int main(void)
{
   Solution s;
   vector<int> nums = {2,2};
   vector<int> ans= s.searchRange(nums, 1);
   cout << ans[0]<<" "<<ans[1];
   return 0;
}