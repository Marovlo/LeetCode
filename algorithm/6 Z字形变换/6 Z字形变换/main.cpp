#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

class Solution {
public:
   string convert(string s, int numRows) {
      vector<string> divisions;
      int len = s.length();
      int pos = 0;
      int flag = 0;
      while (pos < len)
      {
         string temp;
         if (flag == 0)
         {
            for (int i = 0; i < numRows && pos < len; pos++, i++)
            {
               temp += s[pos];
            }
            flag = 1;
         }
         else
         {
            for (int i = 0; i < numRows - 2 && pos < len; pos++, i++)
            {
               temp += s[pos];
            }
            flag = 0;
         }
         divisions.push_back(temp);
      }
      len = divisions.size();
      flag = 0;
      string result;
      for (int j = 0; j < numRows; j++)
      {
         for (int i = 0; i < len; i++)
         {
            if (j == 0 || j == numRows - 1)
            {
               if (i % 2 == 0)
               {
                  if (!divisions[i].empty())
                  {
                     result += divisions[i][0];
                     divisions[i].assign(divisions[i].begin() + 1, divisions[i].end());
                  }
               }
            }
            else
            {
               if (i % 2 != 0)
               {
                  int toout = numRows - j - 2;
                  if (toout < divisions[i].length())
                  {
                     result += divisions[i][toout];
                     divisions[i].pop_back();
                  }
               }
               else
               {
                  if (!divisions[i].empty())
                  {
                     result += divisions[i][0];
                     divisions[i].assign(divisions[i].begin() + 1, divisions[i].end());
                  }
               }
            }

         }
      }
      return result;
   }
};

int main(void)
{
   ifstream f("input.txt");
   string str;
   string num;
   getline(f, str);
   getline(f, num);
   Solution s;
   cout << s.convert(str, atoi((num.c_str())));
   return 0;
}