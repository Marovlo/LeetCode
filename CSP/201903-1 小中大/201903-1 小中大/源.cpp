#include<iostream>
using namespace std;

int main(void)
{
	//freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	int* ar = new int[n] {0};
	for (int i = 0; i < n; ++i)
	{
		cin >> ar[i];
	}
	int max = 0, min = 0;
	if (ar[0] < ar[n - 1])//按升序
	{
		max = ar[n - 1];
		min = ar[0];
	}
	else
	{
		max = ar[0];
		min = ar[n - 1];
	}
	double mid_f = 0;
	int mid = 0;
	if (n % 2 == 0)
	{
		mid_f = (double(ar[n / 2] + ar[n / 2 - 1])) / (double(2));
		if (fabs(mid_f - floor(mid_f) < 1e-5))
		{
			mid = mid_f;
			printf("%d %d %d", max, mid, min);
		}
		else
		{
			printf("%d %.1f %d", max, mid_f, min);
		}
	}
	else
	{
		mid = ar[n / 2];
		printf("%d %d %d", max, mid, min);
	}
	return 0;
}