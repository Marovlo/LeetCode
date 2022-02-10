#include"resources.h"

class Solution
{
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		int i = 0, j = rotateArray.size(), mid = 0;
		while (j>i+1)
		{
			mid = (i + j) / 2;
			if (rotateArray[mid] > rotateArray[0])i = mid;
			else if (rotateArray[mid] < rotateArray[0])j = mid;
		}
		return rotateArray[mid];
	}
};


int main(void)
{
	Solution s;

	return 0;
}