#include"resources.h"

class Solution
{
public:
	double Power(double base, int exponent) {
		//������,����÷ǵݹ�Ŀ�����,����⵱Ȼ����һֱ��ͬһ����,���Ӷ�0(n)
		//�ÿ�����,ÿ�γ��Լ�,�����ǳ˹̶�����,�൱�ڸ��Ӷ�Ϊo(logn)
		//�����ݿ��Եݹ�,���ǵݹ���ܱ�ջ
		//������Ҳ���Էǵݹ�,ָ��ÿ�γ��Զ�,û�����������Լ�,���������Թ̶�����
		//Ԥ����x^-n=(1/x)^n
		if (exponent < 0)
		{
			base = 1.0 / base;
			exponent = -exponent;
		}
		if (exponent == 1)return base;
		else
		{
			return q_power(base, exponent);
		}
	}

	double q_power(double b, int e)
	{
		double res = 1.0;
		double x = b;
		while (e)
		{
			if (e & 1) {
				res *= x;
			}
			x *= x;
			e >>= 1;
		}
		return res;
	}
};


int main(void)
{
	Solution s;
	cout << s.Power(3, 5);
	return 0;
}