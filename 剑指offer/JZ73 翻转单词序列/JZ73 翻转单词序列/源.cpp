#include"resources.h"

class Solution
{
public:
	string ReverseSentence(string str) {
		int len = str.length();
		vector<string> slist;
		string t;
		for (int i = 0; i < len; ++i)
		{
			if (str[i] == ' ')
			{
				slist.push_back(t);
				t.clear();
			}
			else t += str[i];
		}
		slist.push_back(t);
		reverse(slist.begin(), slist.end());
		int size = slist.size();
		string res;
		for (int i = 0; i < size; ++i)
		{
			res.append(slist[i]);
			res += ' ';
		}
		if (res.length() != 0)res.pop_back();
		return res;
	}
};


int main(void)
{
	Solution s;

	return 0;
}