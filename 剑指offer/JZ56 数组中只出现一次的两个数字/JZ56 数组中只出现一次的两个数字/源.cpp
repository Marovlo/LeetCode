#include"resources.h"

int gg(int a, int b)
{
	return a < b;
}

class Solution
{
public:
	
	struct cmp
	{
		bool operator()(int a, int b) { return a > b; };
	};
	vector<int> FindNumsAppearOnce(vector<int>& array) {
		unordered_map<int, int>umapbb; 
		int size = array.size();
		if (size <= 2)return array;
		else {
			for (int i = 0; i < size; ++i)
			{
				if (umapbb.find(array[i]) == umapbb.end())
				{
					umapbb[array[i]] = 1;
				}
				else  umapbb.erase(array[i]);
			}
			vector<int>mm;
			for (unordered_map<int, int>::iterator i = umapbb.begin(); i != umapbb.end(); ++i)mm.push_back((*i).first);
			sort(mm.begin(), mm.end(),gg);
			return mm;
		}
	}
};


int main(void)
{
	Solution s;
	vector<int> cc = { 1,1,2,2,3,3,4,5 };
	vector<int> zz= s.FindNumsAppearOnce(cc);
	cout << zz[0] << " " << zz[1];
	return 0;
}