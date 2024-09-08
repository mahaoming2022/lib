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
const int N=114;

int n,K,D;
ll mem[N][N][N];
vector<ll> a;

ll dp(int i,int k,int s)
{
    ll& ans=mem[i][k][s];
    if(ans!=-1) return ans;
    if(i==n+1)
    {
        if(s==0&&k==K) return 0;
        return -INFL;
    }
    ans=dp(i+1,k,s);
    if(k<K) ans=max(ans,a[i]+dp(i+1,k+1,(s+a[i])%D));
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>n>>K>>D;
    a.resize(n+1);
    rep(i,1,n) cin>>a[i];
    memset(mem,-1,sizeof(mem));
    ll ans=dp(1,0,0);
    cout<<(ans>=0?ans:-1);
}

// hope to debug successfully