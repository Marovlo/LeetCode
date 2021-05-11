#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
   string longestCommonPrefix(vector<string>& strs) {
      int size = strs.size();
      if (size == 0)return "";
      else if (size == 1)return strs[0];
      vector<int> lens;
      for (int i = 0; i < size; i++)
      {
         lens.push_back(strs[i].length());
      }
      int flag = 0;
      string common = "";
      while (true)
      {
         char now = strs[0][flag];
         for (int i = 0; i < strs.size(); i++)
         {
            if (lens[i] > flag)
            {
               if (now != strs[i][flag])
               {
                  flag = -1;
                  break;
               }
            }
            else
            {
               flag = -1;
               break;
            }
         }
         if (flag != -1)
         {
            common += now;
            flag += 1;
         }
         else
         {
            break;
         }
      }
      return common;
   }
};

int main(void)
{
   Solution s;
   vector<string> strs = { "flower","flow","flight" };
   cout << s.longestCommonPrefix(strs);
   return 0;
}