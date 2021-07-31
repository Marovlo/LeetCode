#include<iostream>
using namespace std;

int plus_i(int i, int ji,int n)
{
	return (i + ji) % n;
}

int main(void)
{
	//freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	bool* drop_list = new bool[n] {false};
	int dropped = 0, total_left = 0;
	int max_mi = 0;
	for (int i = 0; i < n; ++i)
	{
		int m, first, now;
		cin >> m >> first;
		max_mi = max_mi > m ? max_mi : m;
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
	if (max_mi != = 100)
	{
		if (dropped < 3)
		{
			cout << total_left << " " << dropped << " " << group;
			return 0;
		}
		else
		{
			for (int i = 0; i < n; ++i)
			{
				if (drop_list[i] && drop_list[plus_i(i, 1, n)] && drop_list[plus_i(i, 2, n)])group += 1;
			}
			cout << total_left << " " << dropped << " " << group;
			return 0;
		}
	}
	else
	{
		if (dropped < 3)
		{
			cout << total_left << " " << dropped << " " << group;
			return 0;
		}
		else
		{
			for (int i = 0; i < n; ++i)
			{
				if (drop_list[i] && drop_list[plus_i(i, 1, n)] && drop_list[plus_i(i, 2, n)])group += 1;
			}
			cout << total_left << " " << dropped << " " << group;
			return 0;
		}
	}
}