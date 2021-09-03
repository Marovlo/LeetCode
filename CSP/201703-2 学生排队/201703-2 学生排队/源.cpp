#include<iostream>
#include<vector>
using namespace std;

int find_index(const vector<int>& vec, const int& to_find)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		if (to_find == vec[i])return i;
	}
}

int main(void)
{
	//freopen("in.txt", "r", stdin);
	vector<int> vec;
	int k, n;
	cin >> k >> n;
	for (int i = 0; i < k; i++)
	{
		vec.push_back(i + 1);
	}
	for (int i = 0; i < n; ++i)
	{
		int to_find, pos, index;
		cin >> to_find >> pos;
		index = find_index(vec, to_find);
		vec.erase(vec.begin() + index);
		vec.insert(vec.begin() + index + pos, to_find);
	}
	for (int i = 0; i < k; ++i)
	{
		cout << vec[i] << " ";
	}
	return 0;

}