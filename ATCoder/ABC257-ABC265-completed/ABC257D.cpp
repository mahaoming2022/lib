#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)

using namespace std;

typedef long long ll;
typedef double db;

const int N=223;

ll p[N];bool vis[N];
pair<ll,ll> a[N];

int n,cnt;

inline void dfs(int o,ll s)
{
    vis[o]=1,++cnt;
    rep(i,1,n) 
        if(!vis[i]&&
        p[o]*s>=abs(a[o].first-a[i].first)+abs(a[o].second-a[i].second))
            dfs(i,s);
}

bool check(ll s)
{
    rep(i,1,n){
        rep(i,1,n) vis[i]=0;
        cnt=0;
        dfs(i,s);
        if(cnt==n) return 1;
    }
    return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n;
    rep(i,1,n) cin>>a[i].first>>a[i].second>>p[i];
    ll l=0,r=4e9;
    while(l+1<r)
    {
        ll mid=l+((r-l)>>1);
        if(check(mid))
            r=mid;
        else l=mid;
    }
    cout<<r;
}