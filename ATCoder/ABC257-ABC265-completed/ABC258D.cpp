#include <bits/stdc++.h>
#define rep(i,l,r) for(ll i=(l);i<=(r);i++)

using namespace std;

typedef long long ll;
typedef double db;

ll n,x;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n>>x;
    ll s=0,mi=LLONG_MAX,ans=LLONG_MAX;
    rep(i,1,n)
    {
        ll a,b;
        cin>>a>>b;
        s+=a+b,mi=min(mi,b),ans=min(ans,s+(x-i)*mi);
    }
    cout<<ans;
}

// debug
// 一定全盘 long long
// 一定 LLONG_MAX