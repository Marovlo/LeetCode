#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
   int minTimeToVisitAllPoints(vector<vector<int>>& points) {
      int len = points.size();
      if (len <= 1)return 0;
      int sum_step = 0;
      for (int i = 0, j = i + 1; j != len; ++j, ++i)sum_step += step2points(points[i], points[j]);
      return sum_step;
   }
   inline int max(int a, int b) { return a > b ? a : b; }
   inline int step2points(const vector<int>& a, const vector<int>& b) { return max(fabs(a[0] - b[0]), fabs(a[1] - b[1])); }
};

int main(void)
{
   return 0;   
}