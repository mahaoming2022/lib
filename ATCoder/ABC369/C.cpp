// Written by da_ke
// Website: https://mahaoming2022.github.io

#include <bits/stdc++.h>

#define i64 long long
#define rep(i,l,r) for(i64 i=(l);i<=(r);i++)
#define fdn(i,r,l) for(int i=(r);i>=(l);i--)
#define pii pair<int,int>
using namespace std;

typedef long long ll;
typedef double db;
typedef __int128 i128;

int n;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>n;
    vector<ll> a(n+1),v;
    rep(i,1,n) cin>>a[i];
    int l=1;
    ll ans=n;
    rep(i,2,n-1)
        if(a[i+1]-a[i]!=a[i]-a[i-1])
            ans+=1ll*(i-l+1)*(i-l+2)/2-(i-l+1),l=i;
    ans+=1ll*(n-l+1)*(n-l+2)/2-(n-l+1);
    cout<<ans;
}