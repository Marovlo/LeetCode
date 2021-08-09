#include<iostream>
#include<vector>
using namespace std;

typedef struct gap
{
	int a, b;
}gap;

int main(void)
{
	//freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	vector<gap> ar, br;
	for (int i = 0; i < n; ++i)
	{
		gap t;
		cin >> t.a >> t.b;
		ar.push_back(t);
	}
	for (int i = 0; i < n; ++i)
	{
		gap t;
		cin >> t.a >> t.b;
		br.push_back(t);
	}
	int sum = 0;
	for (int i = 0, j = 0; i < n && j < n; )
	{
		gap& a = ar[i], & b = br[j];
		//六种关系
		if (a.b <= b.a)//br完全大于ar
		{
			++i;//ar右移
		}
		else if (b.a >= a.a && a.b >= b.a && b.b >= a.b)
		{
			sum += a.b - b.a;
			++i;
		}
		else if (a.b >= b.b && b.b >= a.a && a.a >= b.a)
		{
			sum += b.b - a.a;
			++j;
		}
		else if (b.a >= a.a && b.b <= a.b)
		{
			sum += b.b - b.a;
			++j;
		}
		else if (a.a >= b.a && b.b >= a.b)
		{
			sum += a.b - a.a;
			++i;
		}
		else if (a.a >= b.b)
		{
			++j;
		}
	}
	cout << sum;
}