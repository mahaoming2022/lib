#include <bits/stdc++.h>

#define i64 long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define fdn(i,r,l) for(int i=(r);i>=(l);i--)
#define pii pair<int,int>
using namespace std;

typedef long long ll;
typedef double db;
typedef __int128 i128;

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
std::mt19937_64 rnd64(std::chrono::steady_clock::now().time_since_epoch().count());

int n;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>n;
    db ans=0;
    ll ox=0,oy=0;ll x,y;
    rep(i,1,n)
    {
        
        cin>>x>>y;
        ans+=sqrt(1.0*(x-ox)*(x-ox)+1.0*(y-oy)*(y-oy));
        ox=x,oy=y;
    }
    ox=0,oy=0;
    ans+=sqrt((x-ox)*(x-ox)+(y-oy)*(y-oy));
    printf("%.10lf",ans);
}