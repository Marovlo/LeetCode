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
   int heightChecker(vector<int>& heights) {
      int bucket[101] = { 0 };
      int size = heights.size();
      int ans = 0;
      vector<int> sorted_heights;
      for (int i = 0; i < size; ++i)++bucket[heights[i]];
      for (int i = 1; i < 101; ++i)while (bucket[i]-- != 0)sorted_heights.push_back(i);
      for (int i = 0; i < size; ++i)if (heights[i] != sorted_heights[i])++ans;
      return ans;
   }
};

int main(void)
{
   Solution s;
   
   return 0;
}