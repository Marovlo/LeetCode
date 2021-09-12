#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

int main(void)
{
	freopen("in.txt","r",stdin);
	int n;
	cin>>n;
	unordered_map<int,int> dict;
	for(int i=0;i<n;++i)
	{
		int temp;
		cin>>temp;
		if(dict.find(temp)==dict.end())
		{
			dict[temp]=1;
		}
		else
		{
			dict[temp]+=1;
		}
	}
	int most=INT_MIN,small=INT_MAX;
	for(auto i=dict.begin();i!=dict.end();++i)
	{
		if((*i).second>most)
		{
			most=(*i).second;
			small=(*i).first;
		}
		else if((*i).second==most)
		{
			if((*i).first<small)
			{
				small=(*i).first;
				small=(*i).first;
			}
		}
	}
	cout<<small;
	return 0;
}
