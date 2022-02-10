#include"resources.h"

class Solution
{
public:
	int GetNumberOfK(vector<int> data, int k) {
		int size = data.size();
		if (size == 0)return 0;
		else
		{
			int mid = 0;
			for (int i = 0, j = size; i < j;)
			{
				mid = (i + j) / 2;
				if (k < data[mid])j = mid - 1;
				else if (k > data[mid])i = mid + 1;
				else break;
			}
			if (data[mid] != k)return 0;
			else
			{
				int res = 1;
				int r = mid, l = mid;
				while (++r < size && data[r] == k)++res;
				while (--l >= 0 && data[l] == k)++res;
				return res;
			}
		}
	}
};


int main(void)
{
	Solution s;

	return 0;
}