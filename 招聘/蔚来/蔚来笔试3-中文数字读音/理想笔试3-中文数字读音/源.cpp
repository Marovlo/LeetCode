#include"resources.h"

class Solution {
public:
	string chinese_number(int n) {
		int ar[8]{ 0 }, count = 0;
		while (n)
		{
			ar[count++] = n % 10;
			n /= 10;
		}
		string res = "";
		for (int i = 0; i < count; ++i)
		{
			if (i == 0)res += ar[0] + 48;
			else{
				if (ar[i] == 0 && res.back() != '0' && res.back() != 'w')res += '0';
				else
				{
					switch ((i + 1) % 4)
					{
					case 1:
						res += 'w';
						if (ar[i] != 0)res += ar[i] + 48;
						break;
					case 2:
						if (ar[i] != 0) {
							res += 's';
							res += ar[i] + 48;
							break;
						}
					case 3:
						if (ar[i] != 0) {
							res += 'b';
							res += ar[i] + 48;
							break;
						}
					case 0:
						if (ar[i] != 0) {
							res += 'q';
							res += ar[i] + 48;
							break;
						}
					default:
						break;
					}
				}
				
			}
		}
		for (int i = 0; i < res.length(); ++i)
		{
			if (res[i] == '0')res.erase(res.begin() + i);
			else break;
		}
		reverse(res.begin(), res.end());
		if (res.length() >= 2 && res[0] == '1' && res[1] == 's')res.assign(res.begin() + 1, res.end());
		return res;
	}
};


int main(void)
{
	Solution s;
	cout << s.chinese_number(1100100);
	return 0;
}