#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct cmp
{
	bool operator()(const int &a, const int &b)
	{
		return a < b;
	}
};
	
typedef priority_queue<int, vector<int>,cmp> s_queue;

int main(void)
{
	freopen("in.txt", "r", stdin);
	s_queue q;
	int n, k;
	cin >> n >> k;
	int got = 0;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		q.push(temp);
	}
	while (true)
	{
		int sum = 0;
		++got;
		while (sum<k)
		{
			sum += q.top();
			q.pop();
			if (q.size() == 0)
			{
				cout << got;
				return 0;
			}
		}
	}
}