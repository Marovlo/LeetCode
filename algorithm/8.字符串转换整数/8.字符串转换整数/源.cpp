#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Solution {
public:
   long long max = 2147483647;
   long long min = (-2147483647 - 1);
   int myAtoi(string s) {
      string num = get_number(s);
      if (num == "")return 0;
      long long res=0;
      int neg = num[0] == '-' ? 1 : 0;
      int len = num.length();
      for (int i = neg; i < len; i++)
      {
         res += (num[i] - 48) * pow_10(len - neg - (neg==1?i:i+1));
      }
      res = neg == 1 ? -res : res;
      if (res > max)return max;
      else if (res < min)return min;
      else return res;
   }

   long long pow_10(int power)
   {
      long long result = 1;
      for (int i = 0; i < power; i++)
      {
         result *= 10;
      }
      return result;
   }

   string get_number(string str)
   {
      int len = str.length();
      bool ok = false;
      bool first = true;
      bool zeroed = false;
      string res_num="";
      for (int i = 0; i < len; i++)
      {
         if (!ok)
         {
            if (!isdigit(str[i]))
            {
               if (zeroed)return "";
               if (str[i] == ' ')continue;
               else if (str[i] == '-')
               {
                  ok = true;
                  res_num += '-';
               }
               else if (str[i] == '+')
               {
                  ok = true;
               }
               else
               {
                  return "";
               }
            }
            else if (str[i] == '0')
            {
               zeroed = true;
               continue;
            }
            else
            {
               ok = true;
               res_num += str[i];
            }
         }
         else
         {
            if (isdigit(str[i]))
            {
               if (first && str[i] == '0' && !isdigit(res_num[0]))continue;
               else first = false;
               res_num += str[i];
            }
            else return res_num;
         }
      }
      return res_num;
   }
};

int main(void)
{
   ifstream f("in.txt");
   string line;
   getline(f, line);
   Solution s;
   cout<<s.myAtoi(line);
   return 0;
}