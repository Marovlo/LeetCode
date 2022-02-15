#include"resources.h"

class Solution {
public:
	static bool cmp(string a, string b)
	{
		return a + b < b + a;
	}
	string PrintMinNumber(vector<int> numbers) {
		int size = numbers.size();
		vector<string>sr;
		for (int i = 0; i < size; ++i)sr.push_back(to_string(numbers[i]));
		sort(sr.begin(), sr.end(), cmp);
		string s = "";
		for (int i = 0; i < size; ++i)s += sr[i];
		return s;
	}
};


int main(void)
{
	Solution s;
	
	return 0;
}