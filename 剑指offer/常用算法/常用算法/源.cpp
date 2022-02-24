#include"resources.h"

class Solution {
public:
	vector<int>& quick_sort(vector<int>& nums, int l, int r)//��������
	{
		if (l < r)
		{
			int mid = nums[l];//�����е�һ��Ϊ����
			int tl = l, tr = r;//��ʱ��¼��߽���ұ߽�
			while (tl < tr)
			{
				while (tl < tr && nums[tr] > mid)--tr;//�ұ߽���ڵ�������ʱ,���п�£
				//��ʱ�ұ߳��ֵ�һ��С���������
				while (tl < tr && nums[tl] < mid)++tl;//��߽�С�ڵ�������ʱ,���п�£
				//��ʱ��߳��ֵ�һ�������������
				swap(nums[tl],nums[tr]);//��������������
			}//����߽�����ұ߽�ʱ,�˵�Ϊ�������ڵ�,����߶�С������,�ұ�ȫ����������
			nums[tl] = mid;//��ʱtlΪ����λ��,��������ں��ʵ�λ��
			quick_sort(nums, l, tl - 1);//�ݹ���߽�
			quick_sort(nums, tl + 1, r);//�ݹ��ұ߽�
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