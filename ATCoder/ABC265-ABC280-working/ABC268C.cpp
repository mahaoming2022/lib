#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define pii pair<int,int>

using namespace std;
typedef long long ll;

const int N=2e5+23;

int n;
int p[N],dp[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n;
    rep(i,0,n-1) cin>>p[i];
    rep(i,0,n-1)
    {
        dp[(i-p[i]+n)%n]++;
        dp[(i-p[i]+1+n)%n]++;
        dp[(i-p[i]-1+n)%n]++;
    }
    int ans=0;
    rep(i,0,n-1)
        ans=max(ans,dp[i]);
    cout<<ans;
}

// dbg: 请注意负数取模。