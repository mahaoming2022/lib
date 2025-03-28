// Written by da_ke
// Website: https://mahaoming2022.github.io

#include <bits/stdc++.h>

#define i64 long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define repl(i,l,r) for(i64 i=(l);i<=(r);i++)
#define fdn(i,r,l) for(int i=(r);i>=(l);i--)
#define pii pair<int,int>
using namespace std;

typedef long long ll;
typedef double db;
typedef __int128 i128;

const int INF=1<<29;
const ll INFL=1ll<<59;
const int N=1e6+23;

ll k;

ll check(ll p,ll a)
{
    ll cnt=0,i=p;
    while(1)
    {
        ll j=i;
        while(j%p==0) j/=p,cnt++;
        if(cnt>=a) return i;
        i+=p;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>k;
    ll ans=0;
    ll tk=k;
    repl(p,2,(int)sqrt(k))
        if(tk%p==0)
        {
            ll alph=0;
            while(tk%p==0) tk/=p,alph++;
            ans=max(ans,check(p,alph));
        }
    if(tk>1) ans=max(ans,check(tk,1));
    cout<<ans;
}

// hope to debug successfully