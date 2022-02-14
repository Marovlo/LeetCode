#include"resources.h"

class Solution {
public:
	int FirstNotRepeatingChar(string str) {
		vector<int>ar(130, -1);
		int len = str.length();
		if (len == 0)return -1;
		else
		{
			for (int i = 0; i < len; ++i)
			{
				if (ar[str[i]] == -1)
					ar[str[i]] = i;
				else if (ar[str[i]] != -1 && ar[str[i]] != -2)
					ar[str[i]] = -2;
			}
			for (int i = 0; i < len; ++i)
				if (ar[str[i]] != -1 && ar[str[i]] != -2)
					return i;
			return -1;
		}
	}
};


int main(void)
{
	Solution s;
	cout << s.FirstNotRepeatingChar("google");
	return 0;
}