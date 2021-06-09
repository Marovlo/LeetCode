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
   bool validMountainArray(vector<int>& arr) {
      int len = arr.size();
      if (len < 3)return false;
      int top = 0;
      for (int i = 0; i < len - 1; ++i)
      {
         if (arr[i + 1] < arr[i])
         {
            if (i == 0)return false;
            top = i;
            break;
         }
         else if (arr[i + 1] == arr[i])return false;
      }
      for (int i = top; i < len - 1; i++)
      {
         if (arr[i + 1] >= arr[i])return false;
      }
      return true;
   }
};

int main(void)
{
   Solution s;
   vector<int> arr = { 9,8,7,6,5,4,3,2,1,0 };
   cout << s.validMountainArray(arr);
   return 0;
}