#include<string>
#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<stack>
using namespace std;

class Solution {
public:
   bool validPalindrome(string s)
   {
      int len = s.length();
      if (len == 1)return true;
      bool flag = true;
      for (int i = 0, j = len - 1; i < j; ++i, --j)
      {
         if (s[i] == s[j])continue;
         else
         {
            flag = false;
            if (s[j - 1] == s[i])//adbbdba
            {
               string temp;
               temp.assign(s.begin() + i, s.begin() + j);//注意assgin从begin到begin+n只会复制到n-1为止，第n个不会被复制，一般用法为到end（），尾后迭代器
               flag |= simple_palindrom(temp);
               cout << "右向左移：" << flag << endl;
            }
            if (flag)return true;
            if (s[i + 1] == s[j])//abdbbda
            {
               string temp;
               temp.assign(s.begin() + i + 1, s.begin() + j + 1);
               flag |= simple_palindrom(temp);
               cout << "左向右移：" << flag << endl;
            }
            return flag;
         }
      }
      return flag;
   }
   bool simple_palindrom(const string& s)
   {
      int len = s.length();
      if (len == 1)return true;
      for (int i = 0, j = len - 1; i < j; ++i, --j)
      {
         if (s[i] != s[j])return false;
      }
      return true;
   }
};

int main(void)
{
   Solution s;
   cout << s.validPalindrome("abca") << endl;
   return 0;
}