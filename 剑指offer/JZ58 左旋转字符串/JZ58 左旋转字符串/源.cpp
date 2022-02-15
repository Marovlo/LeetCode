#include"resources.h"

class Solution {
public:
	string LeftRotateString(string str, int n) {
		int len = str.length();
		n %= (len - 1);
		string res = "";
		for (int i = n; i < len; ++i)res += str[i];
		for (int i = 0; i < n; ++i)res += str[i];
		return res;
	}
};


int main(void)
{
	Solution s;
	
	return 0;
}