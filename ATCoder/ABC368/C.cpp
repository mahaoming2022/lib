// #define EXT
#include <bits/stdc++.h>
#ifdef EXT
    #include <bits/extc++.h>
#endif

//define
#define i64 long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define fdn(i,r,l) for(int i=(r);i>=(l);i--)
#define pii pair<int,int>

using namespace std;

// type define
typedef long long ll;
typedef double db;
typedef __int128 i128;
#ifdef EXT
    typedef unsigned int ui;
    typedef unsigned long long ull;
    typedef long double ldb;
#endif

// const integer
const int INF=1<<29;
const ll INFL=1ll<59;
const int N=2e5+3;

int n;
ll a[N],sum[N];

bool check(ll t)
{
    ll x=0;
    rep(i,1,n)
    {
        ll m=3-x%3;
        ll y=a[i];
        if(y<m) x+=y;
        if(y>=m)
        {
            // remaining : 3
            // x=0,1,2,3 m=3
            y=y-m-2,x+=m;
            if(y<=0) continue;
            // remaining : 7
            // x=0,1,2,3 m=3
            // y=2;
            ll r=y/5;x+=3*r;
            ll r0=y-5*r;
            if(r0<=2) x+=r0;
            else x+=3;
        }
    }
    return x<=t;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>n;
    rep(i,1,n) cin>>a[i],sum[i]=sum[i-1]+a[i];
    ll l=0,r=N*1e9+23;
    while(l+1<r)
    {
        ll mid=l+((r-l)>>1);
        if(check(mid))
            r=mid;
        else l=mid;
    }
    cout<<r;
}