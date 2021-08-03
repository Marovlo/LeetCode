#include<iostream>
using namespace std;

typedef struct point
{
	int x, y;
	char kind;
}point;

int main(void)
{
	//freopen("in.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	point* ps = new point[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> ps[i].x >> ps[i].y >> ps[i].kind;
	}
	for (int j = 0; j < m; ++j)
	{
		bool aup = false, adown = false, bup = false, bdown = false, flag = true;
		int seta0, seta1, seta2;
		cin >> seta0 >> seta1 >> seta2;
		for (int i = 0; i < n; ++i)
		{
			int sum = seta0 + seta1 * ps[i].x + seta2 * ps[i].y;
			if (sum > 0)
			{
				if (ps[i].kind == 'A')aup = true;
				else bup = true;
			}
			else
			{
				if (ps[i].kind == 'A')adown = true;
				else bdown = true;
			}
			if ((aup && adown) || (bup && bdown))
			{
				flag = false;
				break;
			}
		}
		if (flag)cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}