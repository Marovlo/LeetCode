#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

class Solution {
public:
   int threeSumClosest(vector<int>& nums, int target) {
      int closet = INT_MAX;
      int diff = INT_MAX;
      int size = nums.size();
      sort(nums.begin(), nums.end());
      for (int i = 0; i < size - 2; i++)
      {
         int left = i + 1, right = size - 1;
         int sum = 0;
         while (left<right)
         {

            sum=nums[i]+nums[left]+nums[right];
            if (abs(sum - target) < abs(target-closet))
            {
               closet = sum;
            }
            if (sum < target)left++;
            else if (sum > target)right--;
            else return closet;
         }
      }
      return closet;
   }
};

int main(void)
{
   vector<int> nums = { 1,1,1,1 };
   Solution s;
   cout << s.threeSumClosest(nums, -100);
   return 0;
}