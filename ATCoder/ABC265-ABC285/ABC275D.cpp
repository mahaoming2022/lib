#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)

using namespace std;
typedef long long ll;
typedef double db;

map<ll,ll> mem;

ll f(ll x)
{
    if(mem[x]!=0) return mem[x];
    if(x==0) return 1;
    return mem[x]=f(floor(1.0*x/2))+f(floor(1.0*x/3));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif  
    ll n;cin>>n;
    cout<<f(n);
}