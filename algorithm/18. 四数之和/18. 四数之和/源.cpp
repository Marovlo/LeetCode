#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
   vector<vector<int>> fourSum(vector<int>& nums, int target) {
      vector<vector<int>>ans;
      int num_size = nums.size();
      if (num_size < 4)return ans;
      sort(nums.begin(), nums.end());
      for (int i = 0; i < num_size; ++i)
      {
         for (int j = i + 1; j < num_size; ++j)
         {
            int left = j + 1, right = num_size - 1;
            int x = nums[i] + nums[j];
            while (left<right)
            {
               int y = nums[left], z = nums[right], sum = x + y + z;
               if (sum == target)
               {
                  ans.push_back({ nums[i],nums[j],y,z });
                  while (left < right && nums[left] == nums[left + 1])left++;
                  while (left < right && nums[right] == nums[right - 1])right--;
                  left++;
                  right--;
               }
               else if (sum < target)left++;
               else right--;
            }
            while (j < num_size - 2 && nums[j] == nums[j + 1])j++;
         }
         while (i < num_size - 2 && nums[i] == nums[i + 1])i++;
      }
      return ans;
   }
};


void show(vector<vector<int>>ans)
{
   int vec_size = ans.size();
   for (int i = 0; i < vec_size; i++)
   {
      int size = ans[i].size();
      for (int j = 0; j < size; j++)
      {
         printf("%d ", ans[i][j]);
      }
      printf("\n");
   }
}

int main(void)
{
   clock_t start = clock();
   vector<int> nums = { 1, 0, -1, 0, -2, 2 };
   Solution s;
   vector<vector<int>>ans = s.fourSum(nums,0);
   clock_t end = clock();
   show(ans);
   printf("%d", end - start);
   return 0;
}