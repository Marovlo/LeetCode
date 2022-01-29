#include"resources.h"

class Solution
{
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		
		if (sequence.size() == 0)return false;
		else return verify(sequence);
	}
	int get_pos(vector<int> sequence, int num)
	{
		int len = sequence.size();
		for (int i = 0; i < len; ++i)
		{
			if (sequence[i] >= num)return i;
		}
		return len;
	}

	bool verify(vector<int> sequence)
	{
		//�ж�һ�������Ƿ�Ϊ�����������ĺ����������,��Ҫ�õ�����������е�֪ʶ�ṹ
		//���ں������Ϊ���Ҹ�,�����������һ��һ��Ϊ���ڵ�,�����ڵ���������ȸ�С,�������ȸ���
		//�������г����һ����֮����������ֿ��Ի���Ϊ������������,��һ��ȫ�ȸ�С,�ڶ���ȫ�ȸ���
		//�ٶ���ֳ��������ν��еݹ�,ֱ��ֻ��һ��Ԫ��Ϊ��.
		int len = sequence.size();
		if (len == 1 || len == 0)return true;
		int root = sequence.back();
		int pos = get_pos(sequence, root);
		for (int i = pos; i < len; ++i)if (sequence[i] < root)return false;
		vector<int> left(sequence.begin(), sequence.begin() + pos),
			right(sequence.begin() + pos, sequence.end() - 1);
		return verify(left) && verify(right);
	}
};


int main(void)
{
	Solution s;

	return 0;
}