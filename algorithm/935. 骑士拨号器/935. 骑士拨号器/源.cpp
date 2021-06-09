#include<iostream>
using namespace std;


class Solution {
public:
   int knightDialer(int n) {
      if (n == 1)return 10;
      else
      {
         unsigned m = 1e9 + 7;
         unsigned last[10] = { 1,1,1,1,1,1,1,1,1,1 };
         unsigned now[10] = { 0 };
         for (int i = 1; i < n; ++i)
         {
            memset(now, 0, sizeof(int) * 10);
            now[1] += (last[8] + last[6]) % m;
            now[2] += (last[7] + last[9]) % m;
            now[3] += (last[4] + last[8]) % m;
            now[4] += ((last[3] + last[9]) % m + last[0]) % m;
            now[6] += ((last[1] + last[7]) % m + last[0]) % m;
            now[7] += (last[2] + last[6]) % m;
            now[8] += (last[1] + last[3]) % m;
            now[9] += (last[4] + last[2]) % m;
            now[0] += (last[4] + last[6]) % m;
            memcpy(last, now, sizeof(int) * 10);
         }
         int sum = 0;
         for (int i = 0; i < 10; ++i)
         {
            sum += now[i];
            sum %= m;
         }
         return sum;
      }
   }
};

int main(void)
{
   Solution s;
   cout << s.knightDialer(3131);
   return 0;
}