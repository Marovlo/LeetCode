#include"resources.h"

class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		int end = sum / 2;
		int t = 0;
		vector<int> ares;
		vector<vector<int>>res;
		for (int i = 1; i <= end; ++i)
		{
			t = 0;
			ares.clear();
			for (int j = i;; ++j)
			{
				t += j;
				ares.push_back(j);
				if (t == sum) { res.push_back(ares); break; }
				if (t > sum)break;
			}
		}
		return res;
	}
};


int main(void)
{
	Solution s;
	vector<vector<int>>res;
	res = s.FindContinuousSequence(100);
	for (int i = 0; i < res.size(); ++i) { show(res[i]); cout << endl; }
	return 0;
}