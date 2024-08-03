#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)

using namespace std;

typedef long long ll;
typedef double db;

const int N=5256;

int n,m;
ll x[N],mem[N][N],a[N];

inline ll dp(int d,int cnt)
{
    ll& ans=mem[d][cnt];
    if(d==n+1) return 0;
    if(ans!=-1) return ans;
    ll ans1,ans0;
    ans1=x[d]+a[cnt+1]+dp(d+1,cnt+1);
    ans0=dp(d+1,0);
    return ans=max(ans1,ans0);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n>>m;
    rep(i,1,n) cin>>x[i];
    rep(i,1,m){int ci;cin>>ci;cin>>a[ci];}
    memset(mem,-1,sizeof(mem));
    cout<<dp(1,0);
}