#include<iostream>
using namespace std;
//#define INT_MIN INT_MIN

class Solution {
public:
   int divide(int dividend, int divisor) {
      if (divisor == 1)return dividend;
      else if (dividend == INT_MIN && divisor == -1)return INT_MAX;
      else if (dividend == divisor)return 1;
      else
      {
         bool minus_zero = (dividend < 0) ^ (divisor < 0);
         unsigned int udividend, udivisor;
         if (dividend == INT_MIN)udividend = unsigned(dividend);
         else udividend= dividend < 0 ? -dividend : dividend;
         if (divisor == INT_MIN)udivisor = unsigned(divisor);
         else udivisor = divisor < 0 ? -divisor : divisor;
         if (udividend < udivisor)return 0;
         else
         {
            unsigned now = udivisor, prev = udivisor;
            int ans = 1;
            while (true)
            {
               prev = now;
               now = now + now;
               if (now <= udividend)
               {
                  ans = ans + ans;
                  if (now == udividend)
                  {
                     return minus_zero ? -ans : ans;
                  }
               }
               else break;
            }
            if (ans > 1000)
            {
               unsigned _16times = udivisor << 4;
               now = prev;
               while (true)
               {
                  now += _16times;
                  if (now <= udividend)
                  {
                     prev = now;
                     ans += 16;
                  }
                  else
                     break;
               }
            }
            while (true)
            {
               prev += udivisor;
               if (prev <= udividend)
                  ++ans;
               else break;
            }
            return minus_zero ? -ans : ans;
         }
      }
   }
};

int main(void)
{
   Solution s;
   cout << s.divide(INT_MIN,INT_MIN);
   return 0;
}