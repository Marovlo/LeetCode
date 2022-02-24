#include"resources.h"

class Solution {
public:
	
};


int main(void)
{
	freopen("in.txt", "r",stdin);
	char in;
	string t;
	vector<string> ar;
	while (scanf("%c",&in)!=EOF)
	{
		if (!isblank(in))t += in;
		else 
		{
			ar.push_back(t);
			t.clear();
		}
	}
	ar.push_back(t);
	int size = ar.size();
	vector<int> ir(size, 0);
	for (int i = 0; i < size; ++i)
	{
		if (ar[i] == "undo")ir[i] = 2;//2=undo
		else if (ar[i] == "redo")ir[i] = 3;//3=redo
		else ir[i] = 1;//1=normal str
		//0=delete
	}
	for (int i = 0; i < size; ++i)
	{
		if (ir[i] == 2)//undo
		{
			for (int j = i - 1; j >= 0; --j)//向前找到第一个正常串
			{
				if (ir[j] == 1)
				{
					ir[j] = 0;//delete
					break;
				}
			}
			//可能找不到，找不到就啥也不做
		}
		else if (ir[i] == 3)//redo
		{
			for (int j = i - 1; j >= 0; --j)
			{
				if (ir[j] == 0)//向前找到第一个被删掉的
				{
					ir[j] = 1;//redo
					break;
				}
			}
			//可能找不到，找不到就啥也不做
		}
	}
	for (int i = 0; i < size; ++i)
	{
		if (ir[i] == 1)
		{
			cout << ar[i];
			if (i != size - 1)cout << " ";
		}
	}
	return 0;
}