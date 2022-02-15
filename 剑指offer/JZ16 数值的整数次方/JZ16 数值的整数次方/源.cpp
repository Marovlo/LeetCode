#include"resources.h"

class Solution
{
public:
	double Power(double base, int exponent) {
		//快速幂,最好用非递归的快速幂,这道题当然可以一直乘同一个数,复杂度0(n)
		//用快速幂,每次乘自己,而不是乘固定底数,相当于复杂度为o(logn)
		//快速幂可以递归,但是递归可能爆栈
		//快速幂也可以非递归,指数每次除以二,没有余数乘以自己,有余数乘以固定底数
		//预处理，x^-n=(1/x)^n
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