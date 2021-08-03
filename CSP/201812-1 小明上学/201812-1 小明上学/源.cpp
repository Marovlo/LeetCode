#include<iostream>
using namespace std;

int main(void)
{
	//freopen("in.txt", "r", stdin);
	int red, yellow, green, n, sum = 0;
	cin >> red >> yellow >> green >> n;
	for (int i = 0; i < n; ++i)
	{
		int now, time;
		cin >> now >> time;
		if (now == 0)sum += time;
		else if (now == 1)sum += time;
		else if (now == 2)sum += time + red;
	}
	cout << sum;
}