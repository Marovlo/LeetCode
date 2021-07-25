#include<iostream>
using namespace std;

int main(void)
{
	freopen("in.txt", "r", stdin);
	int n, k, t, xl, yd, xr, yu;
	cin >> n >> k >> t >> xl >> yd >> xr >> yu;
	int passby = 0, stay = 0;
	int tx, ty;
	for (int i = 0; i < n; ++i)
	{
		int stay_time = 0, stay_flag = 0, pass_flag = 0;;
		for (int j = 0; j < t; ++j)
		{
			cin >> tx >> ty;
			if (tx >= xl && tx <= xr && ty >= yd && ty <= yu)
			{
				pass_flag = 1;
				stay_time++;
				if (stay_time >= k)stay_flag = 1;
			}
			else stay_time = 0;
		}
		if (pass_flag == 1)passby++;
		if (stay_flag == 1)stay++;
	}
	cout << passby << "\n" << stay;
	return 0;
}