#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
   string reverseWords(string s) {
      stack<char> st;
      string res;
      bool flag = false;
      int len = s.length();
      for (int i = 0; i < len; ++i)
      {
         if (s[i] == ' ')
         {
            string temp;
            while (!st.empty())
            {
               temp += st.top();
               st.pop();
            }
            res += temp + ' ';
         }
         else
         {
            st.push(s[i]);
         }
      }
      string temp;
      while (!st.empty())
      {
         temp += st.top();
         st.pop();
      }
      res += temp;
      return res;
   }
};

int main(void)
{
   Solution s;
   cout<<s.reverseWords("Let's take LeetCode contest")<<endl;
   return 0;
}