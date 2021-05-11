#include<stack>
#include<iostream>
#include<string>	

using namespace std;

   class Solution {
   public:
      bool isValid(string s) {
         stack<char> work;
         int len = s.length();
         if (len == 0)return true;
         else work.push(*(s.begin()));
         for (int i = 1; i < len; ++i)
         {
            if (work.empty())
            {
               work.push(s[i]);
            }
            else
            {
               if (match(s[i], work.top()))
               {
                  work.pop();
               }
               else work.push(s[i]);
            }
         }
         return work.size() == 0;
      }
      bool match(char a, char b)
      {
         return a == ')' && b == '(' || a == '}' && b == '{' || a == ']' && b == '[';
      }
   };

int main(void)
{
   string str = "()[]{}";
   Solution s;
   cout<<s.isValid(str);
   return 0;
}