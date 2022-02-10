#include"resources.h"

class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
		if (size == 0)return{};
		int len = num.size();
		if (size > len)return{};
		deque<int> dq;
		vector<int>res;
		for (int i = 0; i < len; ++i)
		{
			while (!dq.empty() && num[i] > num[dq.back()])dq.pop_back();//比自己小的全部弹出去，最后第一个是最大的
			dq.push_back(i);
			if (i - dq.front() >= size)dq.pop_front();//头部过期，出了窗口
			if (i + 1 >= size)res.push_back(num[dq.front()]);//新成了窗口
		}
		return res;
	}
};


int main(void)
{
	Solution s;
	auto res=s.maxInWindows({ 2,3,4,2,6,2,5,1 }, 3);
	res;
	return 0;
}