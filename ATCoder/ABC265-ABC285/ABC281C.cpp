// Written by da_ke
// Website: https://mahaoming2022.github.io

#include <bits/stdc++.h>

#define i64 long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define fdn(i,r,l) for(int i=(r);i>=(l);i--)
#define pii pair<int,int>
using namespace std;

typedef long long ll;
typedef double db;
typedef __int128 i128;

const int INF=1<<29;
const ll INFL=1ll<<59;

ll T;
int n;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>n>>T;
    vector<ll> a(n+1),sum(n+1);
    sum[0]=0;
    rep(i,1,n) cin>>a[i],sum[i]=sum[i-1]+a[i];
    T%=sum[n];
    rep(i,1,n)
    {
        if(sum[i]>T)
        {
            T-=sum[i-1];
            cout<<i<<' '<<T;
            return 0;
        }
    }
}

// hope to debug successfully