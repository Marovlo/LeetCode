#include<stdio.h>
#include<math.h>

class Solution {
public:
   bool isPalindrome(int x) {
      int ar[100];
      int temp = x;
      int power = 0;
      if (temp < 0)return false;
      else
      {
         while (temp > 0)
         {
            ar[power++] = temp % 10;
            temp /= 10;
         }
         for (int i = 0,j=power-1; i<j; i++,j--)
         {
            if (ar[i] != ar[j])return false;
         }
         return true;
      }
   }
};

int main(void)
{
   Solution s;
   printf("%d",s.isPalindrome(-1123211));
   return 0;
}