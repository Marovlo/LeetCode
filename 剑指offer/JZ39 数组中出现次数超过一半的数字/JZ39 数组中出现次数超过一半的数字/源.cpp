#include"resources.h"

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int size = numbers.size();
		if (size == 1)return numbers[0];
		int cond = numbers[0];
		int count = 1;
		
		for (int i = 1; i < size; ++i)
		{
			if (cond == -1)
			{
				cond = numbers[i];
				count = 1;
			}
			else
			{
				if (numbers[i] == cond)++count;
				else
				{
					--count;
					if (count == 0)cond = -1;
				}
			}
		}
		return cond;
	}
};


int main(void)
{
	Solution s;
	
	return 0;
}