#include"resources.h"

class Solution {
public:
    bool isNumeric(string str) {
        regex pattern("(\\s*)(([+,-]?\\d*)?)(([.]{1}\\d*)?)(((\\d+|[.]{1})[e|E]{1}[+,-]?\\d+)?)(\\s*)");
        if (regex_match(str, regex("\\s*")) || regex_match(str, regex("\\s*[+,-]*[.]*[e,E]*[+,-]*\\s*")))
            return false;
        else if (regex_match(str, pattern))
            return true;
        else
            return false;
    }
};


int main(void)
{
	Solution s;
	
	return 0;
}