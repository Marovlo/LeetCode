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
	for (int i = 0; i < n; ++i)
	{	
		int res = 0;
		if (i == 0)res = (ar[i] + ar[i + 1]) / 2;
		else if (i == n - 1)res = (ar[i] + ar[i - 1]) / 2;
		else res = (ar[i - 1] + ar[i] + ar[i + 1]) / 3;
		cout<<res<<" ";
	}
	delete[]ar;
	return 0;
}