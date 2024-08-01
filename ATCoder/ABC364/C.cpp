// #define EXT
#include <bits/stdc++.h>
#ifdef EXT
    #include <bits/extc++.h>
#endif

#define i64 long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define fdn(i,r,l) for(int i=(r);i>=(l);i--)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef double db;
typedef __int128 i128;

const int INF=1<<29;
const ll INFL=1ll<59;

const int N=2e5+24;

int n;ll x,y;
pair<ll,ll> a[N];

bool cmp1(pair<ll,ll> A,pair<ll,ll> B)
{return (A.first>B.first);}

bool cmp2(pair<ll,ll> A,pair<ll,ll> B)
{return (A.second>B.second);}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("in.out","w",stdout);
#endif
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>n>>x>>y;
    rep(i,1,n) cin>>a[i].first;
    rep(i,1,n) cin>>a[i].second;
    int ans1=0,ans2=0;
    sort(a+1,a+1+n,cmp1);
    rep(i,1,n)
    {
        if(x>=a[i].first) x-=a[i].first;
        else if(x<a[i].first) {ans1=i;break;}
    }
    if(!ans1) ans1=n;
    sort(a+1,a+1+n,cmp2);
    rep(i,1,n)
    {
        if(y>=a[i].second) y-=a[i].second;
        else if(y<a[i].second) {ans2=i;break;}
    }
    if(!ans2) ans2=n;
    cout<<min(ans1,ans2);
}