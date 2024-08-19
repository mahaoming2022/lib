#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)

using namespace std;
typedef long long ll;
typedef long double db;

const int N=2e5+23;

int n,m,k;
ll a[N],b[N],c[N],dp[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n>>m>>k;
    rep(i,1,m) cin>>a[i]>>b[i]>>c[i];
    rep(i,1,n) dp[i]=1ll<<59;
    dp[1]=0;
    rep(i,1,k)
    {
        int e;
        cin>>e;
        dp[b[e]]=min(dp[b[e]],dp[a[e]]+c[e]);
    }
    if(dp[n]!=1ll<<59) cout<<dp[n];
    else cout<<-1;
}