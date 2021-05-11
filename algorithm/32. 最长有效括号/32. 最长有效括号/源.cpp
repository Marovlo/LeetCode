#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

typedef struct pos_char
{
   char c;
   int i;
   pos_char(char c, int i) :c(c), i(i) {};
   pos_char() = default;
}pos_char;

class Solution {
public:
   int longestValidParentheses(string s) {
      stack<pos_char> schar;
      vector<int> poss;
      int len = s.length();
      for (int i = 0; i < len; ++i)
      {
         if (!schar.empty())
         {
            if (schar.top().c == '(' && s[i] == ')')
            {
               poss.push_back(schar.top().i);
               poss.push_back(i);
               schar.pop();
            }
            else schar.push(pos_char(s[i], i));
         }
         else schar.push(pos_char(s[i], i));
      }
      sort(poss.begin(), poss.end());
      int max = 1, cur = 1,size=poss.size();
      if (size <= 1)return size;
      else
      {
         for (int i = 0; i < size-1; ++i)
         {
            if (poss[i] + 1 == poss[i + 1])++cur;
            else
            {
               max = max > cur ? max : cur;
               cur = 1;
            }
         }
      }
      max = max > cur ? max : cur;
      return max;
   }
};

int main(void)
{
   Solution s;
   cout<<s.longestValidParentheses(")(()()((()))()())");
   return 0;
}
