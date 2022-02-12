#include"resources.h"

class Solution
{
public:
	int duplicate(vector<int>& numbers) {
		int size = numbers.size();
		if (size == 0)return -1;
		int* ar = new int[size] { 0 };
		for (int i = 0; i < size; ++i)
		{
			if (numbers[i] >= 0 && numbers[i] <= size - 1)
			{
				if (ar[numbers[i]] == 1)return numbers[i];
				else ar[numbers[i]] = 1;
			}
			else return -1;
		}
		return -1;
	}
};


int main(void)
{
	Solution s;

	return 0;
}