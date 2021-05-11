#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
   int removeElement(vector<int>& nums, int val) {
      int size = nums.size();
      if (size == 0)return 0;
      int i = 0, j = size - 1;
      while (i<=j)
      {
         if (nums[i] == val)
         {
            swap(nums[i], nums[j]);
            j--;
         }
         else
         {
            i++;
         }
      }
      return i;
   }
};


int main(void)
{
   vector<int> ori = {0,1,1,1,0};
   Solution s;
   int len = s.removeElement(ori,0);
   cout << len << endl;
   for (int i = 0; i < ori.size(); i++)
   {
      cout << ori[i] << " ";
   }
   return 0;
}