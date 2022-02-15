#include"resources.h"

class Solution
{
public:
    //Insert one char from stringstream
    string str;
    void Insert(char ch) {
        str += ch;
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
        vector<int>ar(130, 0);
        int len = str.length();
        for (int i = 0; i < len; ++i)++ar[str[i]];
        for (int i = 0; i < len; ++i)if (ar[str[i]] == 1)return str[i];
        return '#';
    }
};


int main(void)
{
	Solution s;
	
	return 0;
}