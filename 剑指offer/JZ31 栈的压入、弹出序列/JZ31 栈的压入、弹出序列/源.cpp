#include"resources.h"

class Solution
{
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		stack<int>s;
		int size = pushV.size();
		int j = 0;
		for (int i = 0; i < size;++i)
		{
			s.push(pushV[i]);
			while (!s.empty() && s.top() == popV[j])
			{
				s.pop();
				++j;
			}
		}
		size = popV.size();
		for (; j < size; ++j)
		{
			if (s.top() != popV[j])return false;
			else s.pop();
		}
		return true;
	}
};


int main(void)
{
	Solution s;

	return 0;
}