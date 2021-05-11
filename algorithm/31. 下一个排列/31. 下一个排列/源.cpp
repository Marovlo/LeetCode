#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
   void nextPermutation(vector<int>& nums) {
      int size = nums.size();
      int i = size - 2;
      for (; i >= 0; i--)
      {
         if (nums[i] < nums[i + 1])break;//从后往前找到第一个升序对；
      }
      if (i == -1)
      {
         reverse(nums.begin(), nums.end());
         return;
      }
      for (int j = size - 1; j >= 0; j--)//从后往前找到第一个比刚才的升序对中小的那个数大的数；
      {
         if (nums[j] > nums[i])
         {
            swap(nums[j], nums[i]);//找到后交换小数与刚找到的大数
            break;
         }
      }
      sort(nums.begin() + i + 1, nums.end());//交换后按升序排列原来的小数现在的大数后面的数
      return;
   }
};

int main(void)
{
   vector<int> nums = { 2,3,1 };
   Solution s;
   s.nextPermutation(nums);
   return 0;
}