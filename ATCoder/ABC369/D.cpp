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

const int N=2e5+23;

int n;
vector<ll> a;
ll mem[N][3];

ll dp(int i,int o)
{
    ll& ans=mem[i][o];
    if(ans!=-1) return ans;
    if(i==n+1) return 0;
    ll ans0,ans1;
    if(o==0)
        ans0=dp(i+1,o%2),
        ans1=a[i]*2+dp(i+1,(o+1)%2);
    if(o==1)
        ans0=dp(i+1,o%2),
        ans1=a[i]+dp(i+1,(o+1)%2);
    return ans=max(ans0,ans1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>n;
    a.resize(n+1);
    rep(i,1,n) cin>>a[i];
    memset(mem,-1,sizeof(mem));
    cout<<dp(1,1);
}

// hope to debug successfully