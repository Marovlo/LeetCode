#include"resources.h"

class Solution {
public:
	int GetUglyNumber_Solution(int index) {
		unordered_map<int, bool>umap;
		vector<int>res;
		res.push_back(1);
		umap[1] = true;
		int count = 1;
		int t1, t2, t3;
		for (int i = 0;; ++i)
		{
			t1 = res[i] * 2;
			t2 = res[i] * 3;
			t3 = res[i] * 5;
			if (umap.find(t1) == umap.end())
			{
				umap[t1] = true;
				res.push_back(t1);
			}
			if (umap.find(t2) == umap.end())
			{
				umap[t2] = true;
				res.push_back(t2);
			}
			if (umap.find(t3) == umap.end())
			{
				umap[t3] = true;
				res.push_back(t3);
			}
			sort(res.begin(), res.end(), [](int a, int b)->int {return a < b; });
			if (res.size() >= index *2)break;
		}
		return res[index - 1];
	}
};


int main(void)
{
	Solution s;
	cout << s.GetUglyNumber_Solution(1500);
	return 0;
}