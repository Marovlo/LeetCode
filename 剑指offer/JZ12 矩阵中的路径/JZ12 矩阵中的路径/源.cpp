#include"resources.h"

class myPair :public pair<int, int>
{
public:
	myPair(int a, int b)
	{
		this->first = a;
		this->second = b;
	}
	bool operator==(const myPair& other)const
	{
		return this->first == other.first && this->second == other.second;
	}
};

size_t myPair_hash(const myPair& a)
{
	return hash<int>()(a.first) ^ hash<int>()(a.second);
}

typedef unordered_map<myPair, bool, decltype(&myPair_hash)> myMap;

class Solution
{
public:
	bool res = false;
	bool hasPath(vector<vector<char> >& matrix, string word) {
		int n, m;
		myMap passed;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (word[0] == matrix[i][j])
				{
					while (true)
					{

					}
				}
			}
		}
	}

	bool find(vector<vector<char> >& matrix, int n, int m, myMap passed, string word, int start, int end)
	{
		if()
		
	}
};

int main(void)
{
	Solution s;
	unordered_map<myPair, bool, decltype(&myPair_hash)> passed(100, myPair_hash);
	myPair a(1, 1);
	passed[myPair(1,1)] = true;
	cout << passed[a];
	return 0;
}