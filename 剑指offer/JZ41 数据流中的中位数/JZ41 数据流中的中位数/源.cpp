#include"resources.h"

class Solution
{
public:
    priority_queue<int, vector<int>, greater<int>> g_queue;//小顶堆
    priority_queue<int, vector<int>, less<int>>l_queue;//大顶堆
    //本题用两个堆（优先队列），一个大顶堆，一个小顶堆实现一个获取中位数的数据结构
    //首先将数据加入大顶堆,再将大顶堆的最上面数据加入小顶堆,此时如果小顶堆数据比大顶堆多,
    //则将小顶堆最上面数据加入大顶堆,这样之后,大顶堆中的堆顶大数据都去了小顶堆,小顶堆中的
    //堆顶小数据都去了大顶堆,则大顶堆相当于存下了0-5的数据,由于是大顶堆所以5在堆顶
    //小顶堆中相当于存下了6-10的数据,由于是小顶堆所以6在堆顶
    //多以大顶堆的堆顶和小顶堆的堆顶中有一个或者两个的平均数就是数据流的中位数
    //非常巧妙
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