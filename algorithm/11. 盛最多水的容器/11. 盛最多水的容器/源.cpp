#include<iostream>
#include<vector>
#include<fstream>
#include<string>
using namespace std;

class Solution {
public:
   /*
   int maxArea(vector<int>& height) {
      int size = height.size();
      int maxA = 0;
      for (int i = 0; i < size; i++)
      {
         if(height[i]*(size-i)>maxA)
         {
            for (int j = i + 1; j < size; j++)
            {
               int now = (j - i) * (height[i] < height[j] ? height[i] : height[j]);
               maxA = maxA > now ? maxA : now;
            }
         }
      }
      return maxA;
   }
   */
   int maxArea(vector<int>& height) {
      int size = height.size();
      int res = 0;
      for (int i = 0, j = size - 1; i < j;)
      {
         int now = (j - i+1) * (height[i] < height[j] ? height[i++] : height[j--]);
         res = res < now ? now : res;
      }
      return res;
   }
};

int main(void)
{
   ifstream f("in.txt");
   string str;
   getline(f, str);
   vector<int> nums;
   while (true)
   {
      int pos = str.find_first_of(',');
      if (pos == str.npos)
      {
         nums.push_back(atoi(str.c_str()));
         break;
      }
      string temp;
      temp.assign(str.begin(), str.begin() + pos);
      nums.push_back(atoi(temp.c_str()));
      str.assign(str.begin() + pos + 1, str.end());
   }
   Solution s;
   cout<<s.maxArea(nums);
   return 0;
}