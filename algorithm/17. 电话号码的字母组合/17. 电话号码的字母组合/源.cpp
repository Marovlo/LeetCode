#include<iostream>
#include<vector>
#include<string>
#include<deque>
using namespace std;

class Solution {
public:
   vector<string> rep;
   vector<string> ans;
   Solution()
   {
      rep.push_back("");
      rep.push_back("");
      rep.push_back("abc");//2
      rep.push_back("def");//3
      rep.push_back("ghi");//4
      rep.push_back("jkl");//5
      rep.push_back("mno");//6
      rep.push_back("pqrs");//7
      rep.push_back("tuv");//8
      rep.push_back("wxyz");//9
   }
   vector<string> letterCombinations(string digits)//队列法
   {
      if (digits.length() == 0)return ans;
      deque<string>temp_ans;
      temp_ans.push_back("");
      int len = digits.length();
      for (int i = 0; i < len; ++i)
      {
         string now_rep = rep[digits[i] - '0'];
         int now_len = now_rep.length();
         int size = temp_ans.size();
         for (int p = 0; p < size; ++p)
         {
            string to_add = temp_ans.front();
            temp_ans.pop_front();
            for (int j = 0; j < now_len; ++j)
            {
               temp_ans.push_back(to_add + now_rep[j]);
            }
         }
      }
      ans.assign(temp_ans.begin(), temp_ans.end());
      return ans;
   }
   /*
   vector<string> letterCombinations(string digits) { //递归法
      if (digits.length() == 0)return ans;
      combine("", digits);
      return ans;
   }
   void combine(string comb, string digits)
   {
      if (digits.length() == 0)ans.push_back(comb);
      else
      {
         string now_rep = rep[digits[0] - '0'];
         digits.assign(digits.begin() + 1, digits.end());
         for (char i : now_rep)
         {
            combine(comb + i, digits);
         }
      }
   }
   //*/
};

void show(vector<string> ans)
{
   for (int i = 0; i < ans.size(); i++)
   {
      cout << ans[i] << ", ";
   }
}

int main(void)
{
   Solution s;
   show(s.letterCombinations("23"));
   return 0;
}