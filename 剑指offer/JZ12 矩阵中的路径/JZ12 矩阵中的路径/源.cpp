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
	bool hasPath(vector<vector<char> >& matrix, string word) {
		int rows = matrix.size();
		int cols = matrix[0].size();
		bool res=false;
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				if (dfs(matrix, i, j, word, 0))return true;
			}
		}
		return false;
	}
	bool dfs(vector<vector<char>>& matrix,int i,int j, string& word,int pos)
	{
		if ( i >= matrix.size() || j >= matrix[0].size()\
			|| i < 0 || j < 0|| matrix[i][j] != word[pos])return false;
		else
		{
			if (pos == word.length() - 1)return true;
			bool res = false;
			char temp = matrix[i][j];
			matrix[i][j] = '.';//表示已经走过了
			res = dfs(matrix, i + 1, j, word, pos + 1)\
				|| dfs(matrix, i - 1, j, word, pos + 1)\
				|| dfs(matrix, i, j + 1, word, pos + 1)\
				|| dfs(matrix, i, j - 1, word, pos + 1);
			matrix[i][j] = temp;
			return res;
		}
	}
};

int main(void)
{
	Solution s;
	vector<vector<char>> matrix = { {'a','b','c','e'},{'s','f','c','s'}, {'a','d','e','e'} };
	cout << s.hasPath(matrix, "abcb");
	return 0;
}