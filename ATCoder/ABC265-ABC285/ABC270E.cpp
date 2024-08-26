#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)

using namespace std;
typedef long long ll;
typedef long double db;

const int N=2e5+23;

int n;ll k;
ll a[N];

bool check(ll x)
{
    ll sum=0;
    rep(i,1,n) sum+=min(a[i],x);
    return sum<=k;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n>>k;
    rep(i,1,n) cin>>a[i];
    ll l=0,r=k; 
    while(l+1<r)
    {
        ll mid=l+((r-l)>>1);
        if(check(mid)) l=mid;
        else r=mid; 
    }
    rep(i,1,n)
    {
        k-=min(a[i],l);
        a[i]=max(0ll,a[i]-l);
    }
    rep(i,1,n)
    {
        if(k==0) break;
        if(a[i]) k--,a[i]--;
    }
    rep(i,1,n) cout<<a[i]<<' ';
}