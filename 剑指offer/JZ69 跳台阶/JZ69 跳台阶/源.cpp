#include"resources.h"

class Solution
{
public:
	int jumpFloor(int number) {
		if (number == 1)return 1;
		else if (number == 2)return 2;
		else
		{
			int now = 2, pre = 1, temp = 0;
			for (int i = 2; i < number; ++i)
			{
				temp = now;
				now = now + pre;
				pre = temp;
			}
			return now;
		}
	}
};


int main(void)
{
	Solution s;

	return 0;
}