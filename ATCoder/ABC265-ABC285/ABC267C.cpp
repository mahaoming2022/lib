#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define pii pair<int,int>

using namespace std;
typedef long long ll;

const int N=2e5+23;

ll a[N],sum[N],f[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    int n,m;
    cin>>n>>m;
    rep(i,1,n) cin>>a[i],sum[i]=sum[i-1]+a[i];
    rep(i,1,m) f[1]+=a[i]*i;
    rep(i,2,n-m+1) f[i]=f[i-1]+m*a[m+i-1]-(sum[m+i-2]-sum[i-2]);
    ll ans=-1ll<<59;
    rep(i,1,n-m+1) ans=max(ans,f[i]);
    cout<<ans;
}