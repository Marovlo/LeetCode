#include"resources.h"

class Solution
{
public:
	int StrToInt(string s) {
		while (true)
		{
			if (s[0] == ' ')s.erase(s.begin());
			else if (s[0] == '+' || s[0] == '-' || (s[0] >= '0' && s[0] <= '9'))break;
			else return 0;
		}
		bool flag = true;
		if (s.length() == 0)return 0;
		if (s[0] == '-')flag = false;
		if (s[0] == '+' || s[0] == '-')s.assign(s.begin() + 1, s.end());
		if (s[0] >= '0' && s[0] <= '9')
		{
			while (s[0] == '0')s.erase(s.begin());
			string number;	
			int i = 0;
			int len = s.length();
			do
			{
				number += s[i++];
			} while (s[0] >= '0' && s[0] <= '9' && i <= 10 && i < len);//只取十位，int最多就十位
			long long ll = atoll(number.c_str());
			ll = flag == false ? -ll : ll;
			if (ll > INT_MAX)return INT_MAX;
			else if (ll < INT_MIN)return INT_MIN;
			else return ll;
		}
		else return 0;
	}
};


int main(void)
{
	Solution s;
	cout << atoi("+");
	return 0;
}