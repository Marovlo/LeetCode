#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
   int removeDuplicates(vector<int>& nums) {
      int size = nums.size();
      int len = 0, ptr = 0;
      if (size == 0 || size == 1)return size;
      int now = nums[len];
      for (int i = 0; i < size; ++i)
      {
         if (now != nums[i])
         {
            swap(nums[++len], nums[i]);
            now = nums[len];
         }
      }
      return len+1;
   }
};

int main(void)
{
   vector<int> ori = { 1,1,2};
   Solution s;
   int len = s.removeDuplicates(ori);
   cout << len << endl;
   for (int i = 0; i < ori.size(); i++)
   {
      cout << ori[i]<<" ";
   }
   return 0;
}