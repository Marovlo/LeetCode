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
         if (nums[i] < nums[i + 1])break;//�Ӻ���ǰ�ҵ���һ������ԣ�
      }
      if (i == -1)
      {
         reverse(nums.begin(), nums.end());
         return;
      }
      for (int j = size - 1; j >= 0; j--)//�Ӻ���ǰ�ҵ���һ���ȸղŵ��������С���Ǹ����������
      {
         if (nums[j] > nums[i])
         {
            swap(nums[j], nums[i]);//�ҵ��󽻻�С������ҵ��Ĵ���
            break;
         }
      }
      sort(nums.begin() + i + 1, nums.end());//��������������ԭ����С�����ڵĴ����������
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