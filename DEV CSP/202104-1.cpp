#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
    //freopen("in.txt","r",stdin);
	int n,m,l;
    cin>>n>>m>>l;
    int *h=new int[l]{0};
    for(int i=0;i<n*m;++i)
    {
        int t;
        cin>>t;
        h[t]+=1;
    }
    for(int i=0;i<l;++i)
    {
        cout<<h[i]<<" ";
    }
    return 0;
}

