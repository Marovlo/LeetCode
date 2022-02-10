#include"resources.h"

class Solution
{
public:
	bool Find(int target, vector<vector<int> > array) {
		int rows = array.size();
		int cols = array[0].size();
		for (int i = 0, j = cols - 1; i < rows && j >= 0;)//�����Ͻǳ�����С���������ߣ�������������
		{
			if (array[i][j] > target)--j;//��target�������߼�С��--j
			else if (array[i][j] < target)++i;//��targetС������������++i
			else return true;
		}
		return false;
	}
};


int main(void)
{
	Solution s;

	return 0;
}