#include<iostream>

using namespace std;

int main(void)
{
	//freopen("in.txt", "r", stdin);
	int trees, turns;
	cin >> trees >> turns;
	int total_left = 0, max_index = 0, max_delete = 0;
	for (int i = 0; i < trees; ++i)
	{
		int now_delete = 0, turn_delete = 0, pre_total = 0, temp = 0;
		cin >> pre_total;
		for (int j = 0; j < turns; ++j)
		{
			cin >> temp;
			turn_delete += -temp;
		}
		total_left += pre_total - turn_delete;
		if (turn_delete > max_delete)
		{
			max_delete = turn_delete;
			max_index = i + 1;
		}
	}
	cout << total_left << " " << max_index << " " << max_delete;
	return 0;
}