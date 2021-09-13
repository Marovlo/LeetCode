#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
    //freopen("in.txt","r",stdin);
    int n,l,r,t;
    cin>>n>>l>>r>>t;
    vector<vector<int>> h;
    h.resize(n);
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            int t;
            cin>>t;
            h[i].push_back(t);
        }
    }
    int total=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            int up_i,down_i,left_j,right_j;
            up_i=i-r<0?0:i-r;
            down_i=i+r>=n?n-1:i+r;
            left_j=j-r<0?0:j-r;
            right_j=j+r>=n?n-1:j+r;
            double sum=0;
            int count=0;
            for(int p=up_i;p<=down_i;++p)
            {
                for(int q=left_j;q<=right_j;++q)
                {
                	count+=1;
                    sum+=h[p][q];
                }
            }
            count=0?1:count;
            if(sum/count-t<=1e-5)total+=1;
        }
    }
    cout<<total;
    return 0;
}
