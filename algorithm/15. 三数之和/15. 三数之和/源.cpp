#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<time.h>
using namespace std;

typedef struct pair
{
   int i;
   int j;
   int sum;
}Pair;

bool cmp(Pair a, Pair b)
{
   return a.sum < b.sum;
}

class Solution {
public:
   /*
   vector<vector<int>> threeSum_bak(vector<int>& nums) {
      int num_size = nums.size();
      vector<vector<int>>ans;
      vector<Pair>two_sums;
      sort(nums.begin(), nums.end());
      if (nums.size() < 3)return ans;
      for (int i = 0; i < num_size; i++)
      {
         for (int j = 0; j < i; j++)
         {
            Pair temp;
            temp.i = i;
            temp.j = j;
            temp.sum = nums[i] + nums[j];
            two_sums.push_back(temp);
         }
      }
      int sum_size = two_sums.size();
      sort(two_sums.begin(), two_sums.end(), cmp);
      for (int i = num_size - 1, j = 0; i >= 0 && j < sum_size;)
      {
         if (nums[i] + two_sums[j].sum <= 0)
         {
            if (nums[i] + two_sums[j].sum == 0)
            {
               if (i != two_sums[j].i && i != two_sums[j].j)
               {
                  vector<int> temp_ans;
                  temp_ans.push_back(nums[i]);
                  temp_ans.push_back(nums[two_sums[j].i]);
                  temp_ans.push_back(nums[two_sums[j].j]);
                  sort(temp_ans.begin(), temp_ans.end());
                  int ans_size = ans.size();
                  int flag = 1;
                  for (auto vec : ans)
                  {
                     if (vec[0] == temp_ans[0] && vec[1] == temp_ans[1] && vec[2] == temp_ans[2])
                     {
                        flag = 0;
                        break;
                     }
                  }
                  if (flag == 1)ans.push_back(temp_ans);
               }
            }
            j++;
         }
         else i--;
      }
      return ans;
   }
   //*/
   vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>>ans;
      int num_size = nums.size();
      if (num_size < 3)return ans;
      sort(nums.begin(), nums.end());
      for (int i = 0; i < num_size-2; i++)
      {
         int left = i + 1;
         int right = num_size - 1;
         while (left<right)
         {
            int x = nums[i], y = nums[left], z = nums[right];
            if (x + y + z == 0)
            {
               ans.push_back({ x,y,z });
               while (left < right && nums[left] == nums[left + 1])left++;
               while (right > left && nums[right] == nums[right - 1])right--;
               left++;
               right--;
            }
            else if (x + y + z < 0)left++;
            else right--;
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
   clock_t start=clock();
   vector<int> nums = { -3,-1,0,1,2 };
   Solution s;
   vector<vector<int>>ans= s.threeSum(nums);
   clock_t end = clock();
   show(ans);
   printf("%d", end - start);
   return 0;
}