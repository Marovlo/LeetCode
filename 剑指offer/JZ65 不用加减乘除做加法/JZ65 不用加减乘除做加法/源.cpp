#include"resources.h"

class Solution
{
public:
	int Add(int num1, int num2) {
		//�ӷ���ֳ��޽�λ�ӷ�+��λ
		//�޽�λ�ӷ����ǰ�λ���^
		//��λ���ǰ�λ��&֮������һλ<<1(����Ľ�λָ����ÿһλ���Ƿ��н�λ,���������Ľ�λ)
		//��λ�����޽�λ�ӷ�����ܻ��н�λ,������Ҫѭ��,һֱ����λΪ0,��ʾ�޽�λ
		//��ʱ�޽�λ�ӷ��Ľ����ʱ���ս��
		int c;//��λ;
		while (num2!=0)
		{
			c = (num2 & num1) << 1;
			num1 ^= num2;
			num2 = c;
		}
		return num1;
	}
};


int main(void)
{
	Solution s;

	return 0;
}