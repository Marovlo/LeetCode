#include"resources.h"

class Solution
{
public:
	//˼·����һ��ջdata�������ݣ�������һ��ջmin����������ջ��С����
	//���磬data��������ջ��5, 4, 3, 8, 10, 11, 12, 1
	//	��min������ջ��5, 4, 3��no, no, no, no, 1
	stack<int>s1, s2;
    void push(int value) {
        s1.push(value);
        if (s2.empty())s2.push(value);
        else if (value <= s2.top())s2.push(value);//���ںŲ���ʡ��
    }
    void pop() {
        if (s1.top() == s2.top())//s1 ��ջ��ֻ���ܴ��ڵ���s2ջ��
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