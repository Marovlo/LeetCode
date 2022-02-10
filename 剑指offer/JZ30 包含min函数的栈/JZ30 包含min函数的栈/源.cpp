#include"resources.h"

class Solution
{
public:
	//思路：用一个栈data保存数据，用另外一个栈min保存依次入栈最小的数
	//比如，data中依次入栈，5, 4, 3, 8, 10, 11, 12, 1
	//	则min依次入栈，5, 4, 3，no, no, no, no, 1
	stack<int>s1, s2;
    void push(int value) {
        s1.push(value);
        if (s2.empty())s2.push(value);
        else if (value <= s2.top())s2.push(value);//等于号不能省略
    }
    void pop() {
        if (s1.top() == s2.top())//s1 的栈顶只可能大于等于s2栈顶
        {
            s1.pop();
            s2.pop();
        }
        else s1.pop();
    }
    int top() {
        return s1.top();
    }
    int min() {
        return s2.top();
    }
};


int main(void)
{
	Solution s;

	return 0;
}