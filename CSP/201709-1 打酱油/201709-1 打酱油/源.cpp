#include<iostream>
using namespace std;

int main(void)
{
	//freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	int sum = 0;
	while (n>=10)
	{
		if (n / 10 >= 5)
		{
			sum += 7;
			n -= 50;
		}
		else if (n / 10 >= 3)
		{
			sum += 4;
			n -= 30;
		}
		else
		{
			sum += 1;
			n -= 10;
		}
	}
	cout << sum;
	return 0;
}