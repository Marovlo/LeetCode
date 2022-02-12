#include"resources.h"

class Solution
{
public:
	vector<int> FindGreatestSumOfSubArray(vector<int>& array) {
		int res = 0, temp = 0;
		int size = array.size();
		int l = 0, r = 0;
		int resl = 0, resr = 0;
		for (int i = 0; i < size; ++i)
		{
			++r;
			if (temp + array[i] < 0)
			{
				temp = 0;
				l = i + 1;
				r = l;
			}
			else temp += array[i];
			if (res == temp && resr - resl + 1 < r - l + 1)
			{
				resr = r;
				resl = l;
			}
			else if (res < temp)
			{
				res = temp;
				resr = r;
				resl = l;
			}
		}
		vector<int> resv;
		if (resl == resr)resv.push_back(*max_element(array.begin(), array.end()));
		else resv.assign(array.begin() + resl, array.begin() + resr);
		return resv;
	}
};


int main(void)
{
	Solution s;
	vector<int> array = { 0,0,0,0,-1,1,-2 };
	vector<int>res = s.FindGreatestSumOfSubArray(array);
	for (int i = 0; i < res.size(); ++i)cout << res[i] << " ";
	return 0;
}