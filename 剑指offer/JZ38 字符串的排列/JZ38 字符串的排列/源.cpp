#include"resources.h"

class Solution
{
public:
	vector<string> Permutation(string str) {
		vector<string>res;
		do res.push_back(str);
		while (next_permutation(str.begin(), str.end()));
		return res;
	}
};


int main(void)
{
	Solution s;
	s.Permutation("bca");
	return 0;
}