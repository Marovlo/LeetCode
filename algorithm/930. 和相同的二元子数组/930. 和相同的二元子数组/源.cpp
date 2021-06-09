#include<string>
#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<numeric>
#include<math.h>
#include<algorithm>
using namespace std;

class Solution {
public:
   int numSubarraysWithSum(vector<int>& nums, int goal) {
      int len = nums.size();
      int left = 0, right = 0, sum = 0, ans = 0;
      while (right<len)
      {
         sum += nums[right];
         while (sum>goal)
         {
            sum -= nums[left];//×ó±ß´°¿ÚÓÒÒÆ
            left++;
         }
         int temp = left;
         while (temp<=right&&sum==goal)
         {
            ans++;
            sum -= nums[temp];
            temp++;
         }
         while (temp>left)
         {
            sum += nums[temp - 1];
            temp--;
         }
         right++;
      }
      return ans;
   }
   /*int len = nums.size();
      int total = 0;
      if (goal == 0)
      {
         int count = 0;
         for (int i = 0, j = 0; i < len; ++i)
         {
            if (nums[i] == 0)
            {
               for (j = i; j < len; ++j)
               {
                  if (nums[j] == 0)
                  {
                     total += j - i + 1;
                  }
                  else break;
               }
               i = j;
            }

         }
         return total;
      }
      int zero_factor = 1;
      int this_total = 0;
      int sum = 0;
      for (int i = 0; i < len; ++i)
      {
         sum = 0;
         this_total = 0;
         if(nums[i]==0)
         {
            ++zero_factor;
            continue;
         }
         for (int j = i; j < len; ++j)
         {
            sum += nums[j];
            if (sum == goal)
            {
               ++this_total;
               ++j;
               while (j<len)
               {
                  if (nums[j] == 0)
                  {
                     ++this_total;
                     ++j;
                  }
                  else break;
               }
               break;
            }
         }
         total += this_total * zero_factor;
         zero_factor = 1;
      }
      return total;*/
};

int main(void)
{
   Solution s;
   vector<int> nums{ 0,0,0,0,0 };
   cout << s.numSubarraysWithSum(nums,0);
   return 0;
}