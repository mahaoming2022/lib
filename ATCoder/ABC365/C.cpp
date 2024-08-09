#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)

using namespace std;

typedef long long ll;
typedef double db;

const int N=2e5+23;

int n;ll m;
ll a[N];

inline bool check(ll x)
{
    ll sum=0;
    rep(i,1,n)
        sum+=min(x,a[i]);
    return sum<=m;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n>>m;
    rep(i,1,n) cin>>a[i];
    ll l=0,r=1e15;
    const ll I=1e15;
    while(l+1<r)
    {
        ll mid=l+((r-l)>>1);
        if(check(mid))
            l=mid;
        else r=mid;
    }
    if(l<=I-2) cout<<l;
    else cout<<"infinite";
}