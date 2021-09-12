#include<iostream>
#include<queue>
#include<unordered_map>
#include<string>
using namespace std;

int main(void) {
	//freopen("in.txt","r",stdin);
	string s;
	cin>>s;
	int sum=0;
	int count=1;
	for(int i=0; i<s.length(); ++i) {
		if(s[i]=='-')continue;
		else {
			if(i!=s.length()-1)
				sum+=(s[i]-'0')*(count++);
		}
	}
	sum%=11;
	if(sum!=10) {
		if(s[s.length()-1]-'0'==sum)cout<<"Right";
		else {
			s[s.length()-1]=sum+'0';
			cout<<s;
		}
	}
	else {
		if(s[s.length()-1]=='X')cout<<"Right";
		else
		{
			s[s.length()-1]='X';
			cout<<s;
		}
	}

	return 0;
}

