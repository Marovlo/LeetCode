#include<iostream>
using namespace std;

int main(void)
{
	//freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	bool* drop_list = new bool[n] {false};
	int dropped = 0, total_left = 0;
	for (int i = 0; i < n; ++i)
	{
		int m, first, now;
		cin >> m >> first;
		now = first;
		for (int j = 1; j < m; ++j)
		{
			int a;
			cin >> a;
			if (a > 0)//正整数，重新统计；
			{
				if (a < now)//发生掉果
				{
					drop_list[i] = true;
					dropped += 1;
				}
				now = a;
			}
			else//去掉的果子个数
			{
				now += a;
			}
		}
		total_left += now;
	}
	int group = 0;
	if (dropped < 3)
	{
		cout << total_left << " " << dropped << " " << group;
		return 0;
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			if (drop_list[i] && drop_list[(i + 1) % n] && drop_list[(i + 2) % n])group += 1;
		}
		cout << total_left << " " << dropped << " " << group;
		return 0;
	}
}