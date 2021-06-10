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
   string breakPalindrome(string palindrome) {
      int len = palindrome.length();
      bool flag = false;
      if (len == 1)return "";
      if (len % 2 == 0)
      {
         for (int i = 0; i < len; i++)
         {
            if (palindrome[i] != 'a')
            {
               palindrome[i] = 'a';
               return palindrome;
            }
         }
      }
      else
      {
         int mid = len / 2;
         for (int i = 0; i < len; i++)
         {
            if (palindrome[i] != 'a' && i != mid)
            {
               palindrome[i] = 'a';
               return palindrome;
            }
         }
      }
      palindrome[len - 1] = 'b';
      return palindrome;
   }
};

int main(void)
{
   Solution s;
   cout << s.breakPalindrome("aba");
   return 0;
}