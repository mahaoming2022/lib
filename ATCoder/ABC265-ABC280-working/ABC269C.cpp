#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define pii pair<int,int>

using namespace std;
typedef long long ll;

ll n;
bool nb[65],c[65];

void dfs(int i)
{
    if(i==-1)
    {
        ll ans=0;
        for(ll j=0;j<=63;j++)
            ans+=(1ll<<j)*c[j];
        cout<<ans<<endl;
        return ;
    }
    if(nb[i])
    {
        c[i]=0;dfs(i-1);
        c[i]=1;dfs(i-1);
    }
    else
    {
        c[i]=0;
        dfs(i-1);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n;
    for(ll i=0;i<=63;i++) nb[i]=(n>>i)&1;
    dfs(63);
}