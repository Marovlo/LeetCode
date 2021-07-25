#include<iostream>
using namespace std;

int main(void)
{
	int n;
	int count[4] = { 0 };
	cin >> n;
	for (int i = 1, j = 0; i <= n; ++i)
	{
		if (i % 7 == 0 || (i / 100) == 7 || (i - i / 100 * 100) / 10 == 7 || (i - i / 100 * 100 - (i - i / 100 * 100) / 10 * 10) == 7)
		{
			count[j]++;
			n++;
		}
		if (j != 3)j++;
		else j = 0;
	}
	for (int i = 0; i < 4; ++i)
	{
		cout << count[i] << endl;
	}
	return 0;
}