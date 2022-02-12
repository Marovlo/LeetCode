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
		//max_element��std����������һ������������ֵ�ĵ�����������Ϊ���п�ʼ�ĵ������ͽ����ĵ�����������������Ϊ��ѡ�Ƚϵķº���
		//ע���Ƿº������ýṹ�����أ����������
		//���������������Ϊ����������ⲻ��һ�α�����������һ�α�������ɣ�����max����д������ı�����
	}
};


int main(void)
{
	Solution s;

	return 0;
}