#include"resources.h"

class Solution {
public:
	vector<int> multiply(const vector<int>& A) {
		int size = A.size();
		vector<int>B(size);
		int res = 1;
		for (int i = 0; i < size; ++i)
		{
			res = 1;
			for (int j = 0; j < size; ++j)
			{
				if (j != i)res *= A[j];
			}
			B[i] = res;
		}
		return B;
	}

	void show(vector<int> data)
	{
		int size = data.size();
		for (int i = 0; i < size; ++i)cout << data[i] << ' ';
	}
};


int main(void)
{
	Solution s;
	vector<int> A{ 1,2,3,4,5 };
	s.show(s.multiply(A));
	return 0;
}