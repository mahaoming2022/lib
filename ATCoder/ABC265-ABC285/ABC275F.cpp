#include <bits/stdc++.h>

#define i64 long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define fdn(i,r,l) for(int i=(r);i>=(l);i--)
#define pii pair<int,int>
using namespace std;

typedef long long ll;
typedef double db;
typedef __int128 i128;

int n,m;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>n>>m;
    vector<int> a(n+1);
    vector<vector<int>> dp(n+1,vector<int> (m+1,1<<29));
    vector<int> f(m+1,1<<29);
    rep(i,1,n) cin>>a[i];
    dp[0][0]=0,f[0]=0;
    rep(i,1,n)
    {
        rep(j,0,m)
        {
            if(j>=a[i]) dp[i][j]=dp[i-1][j-a[i]];
            dp[i][j]=min(dp[i][j],f[j]+1);
            f[j]=min(f[j],dp[i][j]);
        }
    }
    rep(j,1,m)
        cout<<((dp[n][j]==1<<29)?-1:dp[n][j])<<endl;
}