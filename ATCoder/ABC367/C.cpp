#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)

using namespace std;
typedef long long ll;
typedef double db;

int n,k;
int r[114],c[114];

void dfs(int i,int sum)
{
    if(i==n+1)
    {
        if(sum%k==0)
        {
            rep(i,1,n)
                cout<<c[i]<<' ';
            cout<<endl;
        }
        return ;
    }
    rep(j,1,r[i])
        c[i]=j,
        dfs(i+1,sum+j);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif  
    cin>>n>>k;
    rep(i,1,n) cin>>r[i];
    dfs(1,0);
}