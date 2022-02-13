#include"resources.h"

class Solution
{
public:
	int InversePairs_1(vector<int> data) {// o(n^2)
		int size = data.size();
		if (size <= 0)return 0;
		else
		{
			int res = 0;
			for (int i = 0; i < size; i++)
			{
				for (int j = i + 1; j < size; j++)
				{
					if (data[i] > data[j])res = ++res % 1000000007;
				}
			}
			return res;
		}
	}
		int InversePairs(vector<int> data)// quick sort
		{
			int size = data.size();
			if (size <= 1)return 0;
			else
			{
				int key = data[0];
				vector<int> small, big;
				int res = 0;
				for (int i = 1; i < size; ++i)
				{
					if (data[i] < key)
					{
						++res;//���ȼ�һ����Ϊ���Լ�С������һ�������
						res += big.size();//�ټ�big��size���ڴ�i֮ǰ����key��
						res %= 1000000007;
						//���Ѿ��ӵ�big��ȥ����ֻҪ����key��һ����i������big���ִ��
						//���ʹ�iһ�����������
						small.push_back(data[i]);
					}
					else
					{
						big.push_back(data[i]);
					}
				}
				res += InversePairs(small);
				res %= 1000000007;
				res += InversePairs(big);
				res %= 1000000007;
				return res;
			}
		}
};


int main(void)
{
	Solution s;
	cout << s.InversePairs({ 1,2,3,4,5,6,7,0 });
	return 0;
}