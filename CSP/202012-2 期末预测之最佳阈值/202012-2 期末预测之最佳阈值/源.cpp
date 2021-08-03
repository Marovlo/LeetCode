#include<iostream>
#include<unordered_map>

using namespace std;

int main(void)
{
	freopen("in.txt", "r", stdin);
	int m;
	cin >> m;
	int* y = new int[m] {0};
	int* result = new int[m] {0};
	for (int i = 0; i < m; ++i)
	{
		cin >> y[i] >> result[i];
	}
	int max_yu = y[0];
	int max_correct = 0;
	unordered_map<int, int> already;
	for (int i = 0; i < m; ++i)
	{
		int now_yu = y[i];
		int correct = 0;
		if (already.find(i) == already.end())
		{
			already[i] = 1;
			for (int j = 0; j < m; ++j)
			{
				if (now_yu > y[j] && result[j] == 0)++correct;
				else if (now_yu <= y[j] && result[j] == 1)++correct;
			}
			if (correct < max_correct) {break;}
			else
			{
				if (correct > max_correct)max_yu = now_yu;
				else if (correct == max_correct)max_yu = now_yu > max_yu ? now_yu : max_yu;
				max_correct = correct;
			}
		}
		
	}
	cout << max_yu;
}