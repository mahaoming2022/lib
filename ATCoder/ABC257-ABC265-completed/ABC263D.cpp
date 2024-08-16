#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)

using namespace std;

typedef long long ll;
typedef double db;

const int N=2e5+23;

int n;
ll l,r,a[N],g[N],s[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n>>l>>r;
    rep(i,1,n) cin>>a[i],s[i]=s[i-1]+a[i];
    g[0]=0;
    rep(i,1,n) g[i]=min(g[i-1],i*l-s[i]);
    ll ans=1ll<<59;
    rep(i,0,n) ans=min(ans,s[n-i]+i*r+g[n-i]);
    cout<<ans;
}

/*
思路：
设 s(i)=sigema 1~i a[i]
f(x,y)=x*l-s(x)+s(n-y)+y*r=s(n-y)+y*r+g(x),求f(x,y)的最小值。
枚举 y, 关键：g(x)=x*l-s(x) x belong to [0,n-y];
f(0,0)=x*0-s(0)+s(n)+0=s(n)
f(x,0)=x*l-s(x)+s(n)=min i [0,n] g(i)
g(0)=0
*/