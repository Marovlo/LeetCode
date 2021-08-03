#include<iostream>
#include<vector>

using namespace std;

typedef struct point
{
	int x;
	int y;
	int base_score = 0;
	int extra_score = 0;
};

int main(void)
{
	//freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	vector<point> ps;
	for (int i = 0; i < n; ++i)
	{
		point t;
		cin >> t.x >> t.y;
		ps.push_back(t);
	}
	int scores[5] = { 0 };
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (j != i)
			{
				if (ps[i].y == ps[j].y + 1 || ps[i].y == ps[j].y - 1)//上下关系
				{
					if (ps[i].x == ps[j].x)++ps[i].base_score;
					else if (ps[i].x == ps[j].x + 1 || ps[i].x == ps[j].x - 1)++ps[i].extra_score;
				}
				else if (ps[i].y == ps[j].y && (ps[i].x == ps[j].x + 1 || ps[i].x == ps[j].x - 1))++ps[i].base_score;
			}
		}
		if (ps[i].base_score == 4)++scores[ps[i].extra_score];
	}
	for (int i = 0; i < 5; ++i)
	{
		cout << scores[i] << endl;
	}
	return 0;
}