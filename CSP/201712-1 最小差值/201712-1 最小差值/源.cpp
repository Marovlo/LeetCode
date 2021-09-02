#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(void)
{
	//freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	int* nums = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
	}
	int min = INT_MAX;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			min = abs(nums[i] - nums[j]) < min ? abs(nums[i] - nums[j]) : min;
		}
	}
	cout << min;
	delete[] nums;
	return 0;
}