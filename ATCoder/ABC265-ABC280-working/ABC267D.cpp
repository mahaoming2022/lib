#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define pii pair<int,int>

using namespace std;
typedef long long ll;

const int N=2e3+23;

int n,m;
ll a[N],mem[N][N];

ll dp(int i,int j)
{
    ll& ans=mem[i][j];
    if(j==m+1) return 0;
    if(i==n+1) return -1ll<<59;
    if(ans!=-1) return ans;
    ans=dp(i+1,j);
    if(j<=m) ans=max(ans,j*a[i]+dp(i+1,j+1));
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n>>m;
    rep(i,1,n) cin>>a[i];
    memset(mem,-1,sizeof(mem));
    cout<<dp(1,1);
}

// dbg: 不开 long long 见祖宗
// 必须选满 m 个