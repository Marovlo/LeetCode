#include<stdio.h>
#include<stdlib.h>

class Solution {
public:
   long long max = 2147483647;
   long long min = (-2147483647 - 1);
   int reverse(int x) {
      long long temp = x;
      temp = temp < 0 ? -temp : temp;
      long long result = 0;
      int pow = 0;
      for (int i = 0; ;i++)
      {
         if (temp / pow_10(i) > 0)pow++;
         else break;
      }
      for (int i = 0; i < pow; i++)
      {
         result += (temp % 10) * pow_10(pow - i-1);
         temp /= 10;
      }
      if (result > max || result < min)
      {
         return 0;
      }
      return x<0?-result:result;
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
};

int main(void)
{
   Solution s;
   printf("%d", s.reverse(-2147483648));
   return 0;
}