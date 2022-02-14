#include"resources.h"

class Solution {
public:
	string replaceSpace(string s) {
		int pos=s.find(' ');
		while (pos != s.npos)
		{
			s.replace(s.begin() + pos, s.begin() + pos + 1, "%");
			s.insert(pos + 1, "20");
			pos = s.find(' ');
		}
		return s;
	}
};


int main(void)
{
	Solution s;
	cout << s.replaceSpace("This is a nice day.");
	return 0;
}