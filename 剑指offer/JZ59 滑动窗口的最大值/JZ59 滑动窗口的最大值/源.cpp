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
			while (!dq.empty() && num[i] > num[dq.back()])dq.pop_back();//���Լ�С��ȫ������ȥ������һ��������
			dq.push_back(i);
			if (i - dq.front() >= size)dq.pop_front();//ͷ�����ڣ����˴���
			if (i + 1 >= size)res.push_back(num[dq.front()]);//�³��˴���
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