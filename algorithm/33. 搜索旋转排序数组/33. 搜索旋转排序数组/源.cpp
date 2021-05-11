#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
   int search(vector<int>& nums, int target) {
      int size = nums.size();
      for (int i = 0; i < size; ++i)
      {
         if (target == nums[i])return i;
      }
      return -1;

   }
};

int main(void)
{
   Solution s;
   vector<int> nums = { 1,2,3,4,5 };
   cout<<s.search(nums, 3);
   return 0;
}