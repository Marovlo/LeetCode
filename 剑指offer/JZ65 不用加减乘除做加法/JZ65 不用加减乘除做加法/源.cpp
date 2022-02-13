#include"resources.h"

class Solution
{
public:
	int Add(int num1, int num2) {
		//加法拆分成无进位加法+进位
		//无进位加法就是按位异或^
		//进位就是按位与&之后左移一位<<1(这里的进位指的是每一位上是否有进位,而不是最后的进位)
		//进位加上无进位加法后可能还有进位,所以需要循环,一直到进位为0,表示无进位
		//此时无进位加法的结果就时最终结果
		int c;//进位;
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