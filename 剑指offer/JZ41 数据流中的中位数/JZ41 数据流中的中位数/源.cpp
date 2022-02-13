#include"resources.h"

class Solution
{
public:
    priority_queue<int, vector<int>, greater<int>> g_queue;//С����
    priority_queue<int, vector<int>, less<int>>l_queue;//�󶥶�
    //�����������ѣ����ȶ��У���һ���󶥶ѣ�һ��С����ʵ��һ����ȡ��λ�������ݽṹ
    //���Ƚ����ݼ���󶥶�,�ٽ��󶥶ѵ����������ݼ���С����,��ʱ���С�������ݱȴ󶥶Ѷ�,
    //��С�������������ݼ���󶥶�,����֮��,�󶥶��еĶѶ������ݶ�ȥ��С����,С�����е�
    //�Ѷ�С���ݶ�ȥ�˴󶥶�,��󶥶��൱�ڴ�����0-5������,�����Ǵ󶥶�����5�ڶѶ�
    //С�������൱�ڴ�����6-10������,������С��������6�ڶѶ�
    //���Դ󶥶ѵĶѶ���С���ѵĶѶ�����һ������������ƽ������������������λ��
    //�ǳ�����
    void Insert(int num) {
        l_queue.push(num);
        g_queue.push(l_queue.top());
        l_queue.pop();
        if (g_queue.size() > l_queue.size())
        {
            l_queue.push(g_queue.top());
            g_queue.pop();
        }
    }

    double GetMedian(){
        int size = l_queue.size() + g_queue.size();
        if (size % 2 == 0)
            return (static_cast<double>(l_queue.top()) + static_cast<double>(g_queue.top())) / 2;
        else
        {
            if (l_queue.size() > g_queue.size())return l_queue.top();
            else
                return g_queue.top();
        }
    }
};


int main(void)
{
	Solution s;
    s.g_queue.push(5);
    s.g_queue.push(10);
    s.g_queue;
	return 0;
}