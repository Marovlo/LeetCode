#include<iostream>
using namespace std;

int main(void)
{
	freopen("in.txt", "r", stdin);
	int sum = 0;
	int last = 1;
	while (true)
	{
		int m;
		cin >> m;
		if (m == 0)break;
		if (m == 2)
		{
			if (last == 1)
			{
				sum += 2;
				last = 2;
			}
			else
			{
				sum += last + 2;
				last += 2;
			}
		}
		else if (m == 1)
		{
			last = 1;
			sum += 1;
		}
	}
	cout << sum;
	return 0;
}