#include<iostream>
using namespace std;


typedef struct item
{
	int index;
	int value;
}item;

int main(void)
{
	freopen("in.txt", "r", stdin);
	int n, a, b;
	cin >> n >> a >> b;
	item* isa = new item[a], * isb = new item[b];
	for (int i = 0; i < a; ++i)
	{
		cin >> isa[i].index >> isa[i].value;
	}
	for (int i = 0; i < b; ++i)
	{
		cin >> isb[i].index >> isb[i].value;
	}
	long long sum = 0;
	for (int i = 0, j = 0; i < a && j < b;)
	{
		if (isa[i].index < isb[j].index)++i;
		else if (isa[i].index > isb[j].index)++j;
		else
		{
			sum += isa[i].value * isb[j].value;
			++i;
			++j;
		}
	}
	cout << sum;
	return 0;
}