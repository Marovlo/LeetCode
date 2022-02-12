#include"resources.h"

class Solution
{
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int res = 0, tmp = 0;
		int size = array.size();
		for (int i = 0; i < size; ++i)
		{
			if (tmp + array[i] < 0)tmp = 0;
			else tmp += array[i];
			res = res > tmp ? res : tmp;
		}
		return res == 0 ? *max_element(array.begin(), array.end()) : res;
		//max_element是std函数，返回一个序列中最大的值的迭代器，参数为序列开始的迭代器和结束的迭代器，第三个参数为可选比较的仿函数
		//注意是仿函数，用结构体重载（）运算符。
		//少用这个函数，因为这个函数避免不了一次遍历，尽量在一次遍历中完成，即该max可以写到上面的遍历中
	}
};


int main(void)
{
	Solution s;

	return 0;
}