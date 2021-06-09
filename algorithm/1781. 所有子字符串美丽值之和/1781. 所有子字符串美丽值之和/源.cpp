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
   int beautySum(string s) 
   {
      int len = s.length();
      if (len <= 2)return 0;
      int sum=0;
      for (int i = 0; i < len - 2; ++i)
      {
         int times[26] = { 0 };
         times[s[i] - 'a'] += 1;
         times[s[i + 1] - 'a'] += 1;
         for (int j = i + 2; j < len; ++j)
         {
            times[s[j] - 'a'] += 1;
            int max = INT_MIN, min = INT_MAX;
            for (int p = 0; p < 26; ++p)
            {
               if (times[p] != 0)
               {
                  if (times[p] > max)max = times[p];
                  if (times[p] < min)min = times[p];
               }
            }
            sum += max - min;
         }
      }
      return sum;
   }
};

int main(void)
{
   Solution s;
   cout << s.beautySum("aabcbaa");
   return 0;
}