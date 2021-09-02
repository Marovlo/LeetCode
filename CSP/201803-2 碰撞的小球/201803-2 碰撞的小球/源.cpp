#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

typedef struct ball
{
	int pos;
	enum direction
	{
		left=1,
		right=2,
	};
	direction dir = right;
}ball;

int main(void)
{
	//freopen("in.txt", "r", stdin);
	int n, l, t;
	cin >> n >> l >> t;
	ball* bals = new ball[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> bals[i].pos;
	}
	for (int i = 0; i < t; ++i)
	{
		for (int i = 0; i < n; ++i)//第一次遍历球，移动和处理撞墙反向
		{
			if (bals[i].pos == 0 && bals[i].dir == ball::left)
			{
				bals[i].pos = 1;
				bals[i].dir = ball::right;
			}
			else if (bals[i].pos == l && bals[i].dir == ball::right)
			{
				bals[i].pos = l - 1;
				bals[i].dir = ball::left;
			}
			else
			{
				if (bals[i].dir == ball::right)++bals[i].pos;
				else --bals[i].pos;
			}
		}
		unordered_map<int, vector<int>> poss;
		for (int i = 0; i < n; ++i)
		{
			poss[bals[i].pos].push_back(i);
		}
		for (auto i = poss.begin(); i != poss.end(); ++i)
		{
			if ((*i).second.size() == 2)
			{
				bals[(*i).second[0]].dir = bals[(*i).second[0]].dir == ball::right ? ball::left : ball::right;
				bals[(*i).second[1]].dir = bals[(*i).second[1]].dir == ball::right ? ball::left : ball::right;
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		cout << bals[i].pos << " ";
	}
}