#include<iostream>
#include<queue>
using namespace std;

typedef struct POINT
{
	int x, y, index, distance;
}point;

struct cmp
{
	bool operator()(point a, point b)
	{
		if (a.distance != b.distance)
			return a.distance > b.distance;
		else
			return a.index > b.index;
	}
};

typedef priority_queue<point, vector<point>, cmp> g_queue;



int main(void)
{
	freopen("in.txt", "r", stdin);
	int n, x, y;
	cin >> n>>x>>y;
	g_queue q;
	for (int i = 1; i <= n; ++i)
	{
		point p;
		cin >> p.x >> p.y;
		p.index = i;
		p.distance = (p.x - x) * (p.x - x) + (p.y - y) * (p.y - y);
		q.push(p);
	}
	for (int i = 0; i < 3; i++)
	{
		cout << q.top().index<<endl;
		q.pop();
	}
	return 0;
}