#include<string>
#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;

class Solution {
public:
   vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
      int size = edges.size();
      if (size == 1)return edges[0];
      int* degree;
      degree = (int*)malloc(sizeof(int) * n);
      for (int i = 0; i < size; ++i)++degree[edges[i][0]];
      for(int i=0;i<n;i)

   }
};

int main(void)
{
   Solution s;
   
   return 0;
}