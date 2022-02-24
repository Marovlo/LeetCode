#include"resources.h"

class Solution {
public:
	vector<int>& quick_sort(vector<int>& nums, int l, int r)//快速排序
	{
		if (l < r)
		{
			int mid = nums[l];//以序列第一个为枢轴
			int tl = l, tr = r;//临时记录左边界和右边界
			while (tl < tr)
			{
				while (tl < tr && nums[tr] > mid)--tr;//右边界大于等于枢轴时,向中靠拢
				//此时右边出现第一个小于枢轴的数
				while (tl < tr && nums[tl] < mid)++tl;//左边界小于等于枢轴时,向中靠拢
				//此时左边出现第一个大于枢轴的数
				swap(nums[tl],nums[tr]);//把这两个数交换
			}//当左边界等与右边界时,此点为枢轴所在点,且左边都小于枢轴,右边全部大于枢轴
			nums[tl] = mid;//此时tl为枢轴位置,将枢轴放在合适的位置
			quick_sort(nums, l, tl - 1);//递归左边界
			quick_sort(nums, tl + 1, r);//递归右边界
		}
		return nums;
	}
};


int main(void)
{
	Solution s;
	vector<int>ar{ 7,3,9,8,2,6,5,4,1 };
	show(s.quick_sort(ar, 0, ar.size() - 1));
	return 0;
}