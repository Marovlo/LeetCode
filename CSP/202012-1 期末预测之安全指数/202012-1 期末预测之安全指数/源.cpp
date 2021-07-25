#include<iostream>
using namespace std;

int main(void)
{
	//freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	int sum=0;
	for (int i = 0; i < n; ++i)
	{
		int score, w;
		cin >> w >> score;
		sum += score * w;
	}
	cout << (sum > 0 ? sum : 0);
	return 0;
}