#include"resources.h"

class Solution {
public:
    vector<int> unique(vector<int>& list) {
        unordered_set<int> uset;
        vector<int>res;
        int size = list.size();
        for (int i = 0; i < size; ++i) {
            if (uset.find(list[i]) == uset.end()) {
                uset.insert(list[i]);
                res.push_back(list[i]);
            }
        }
        return res;
    }
};


int main(void)
{
	Solution s;
	
	return 0;
}