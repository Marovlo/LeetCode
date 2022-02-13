#include"resources.h"

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        sort(input.begin(), input.end());
        vector<int>res;
        for (int i = 0; i < k; ++i)res.push_back(input[i]);
        return res;
    }
};


int main(void)
{
	Solution s;

	return 0;
}