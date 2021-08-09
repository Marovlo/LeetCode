#include<iostream>
using namespace std;

enum direction
{
	right,
	left
};

typedef struct pos
{
	bool has_ball = false;

	bool direct = direction::right;
};

int main(void)
{
	int n, l, t;
	cin >> n >> l >> t;
	pos* poss = new pos[l];
	for (int i = 0; i < n; ++i)
	{
		int p;
		cin >> p;
		poss[p].has_ball = true;
	}
	for (int i = 0; i < t; ++i)
	{
		for (int j = 0; j < l; ++j)//移动
		{
			if (poss[j].has_ball)
			{
				if (poss[j].direct == direction::right && j == l - 1)//撞右墙向左走
				{
					poss[j].direct == direction::left;
				}
				else if (poss[j].direct == direction::left && j == 0)//撞左墙向右走
				{
					poss[j].direct = direction::right;
				}
				else
				{
					poss[j].has_ball = false;
					if (poss[j].direct == direction::right)
					{
						poss[j + 1].has_ball = true;
					}
					else
					{
						poss[j - 1].has_ball = true;
					}
				}
			}
		}
	}
}