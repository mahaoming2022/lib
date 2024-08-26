#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)

using namespace std;
typedef long long ll;
typedef long double db;

const int N=2e5+23;

int n,k;
int a[N],dp[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n>>k;
    rep(i,1,k) cin>>a[i];
    rep(i,1,n)
        rep(j,1,k)
            if(a[j]<=i)
                dp[i]=max(dp[i],i-dp[i-a[j]]); 
    cout<<dp[n];
}