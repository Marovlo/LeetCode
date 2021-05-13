#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
   int searchInsert(vector<int>& nums, int target) {
      int l = 0, r = nums.size() - 1;
      int m = 0;
      if (target > nums.back())return nums.size();
      else if (target < nums[0])return 0;
      while (l < r)
      {
         m = (l + r) / 2;
         if (target == nums[m])return m;
         else if (target < nums[m])
         {
            r = m - 1;
            if (target > nums[r])return m;
         }
         else
         {
            l = m + 1;
            if (nums[l] > target)return m + 1;
         }
      }
      if (target == nums[l])return l;
      else
         return m > l ? l + 1 : l;
   }
};

int main(void)
{
   Solution s;
   vector<int> nums = { 1,2,4,6,7};
   cout << s.searchInsert(nums, 3);
   return 0;
}