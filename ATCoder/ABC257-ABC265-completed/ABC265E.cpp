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

const int N=314;

int n,m,a,b,c,d,e,f;
ll mem[N][N][N];
set<pair<ll,ll> > s;

ll dp(int i,int j,int k)
{
    ll& ans=mem[i][j][k];
    if(ans!=-1) return ans;
    ll x=a*i+c*j+e*k,y=b*i+d*j+f*k;
    if(s.find({x,y})!=s.end()) return 0;
    if(i+j+k==n) return 1;
    ans=dp(i+1,j,k)+dp(i,j+1,k)+dp(i,j,k+1);
    return ans=ans%998244353;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>n>>m;
    cin>>a>>b>>c>>d>>e>>f;
    rep(i,1,m)
    {
        ll xi,yi;
        cin>>xi>>yi;
        s.insert({xi,yi});
    }
    memset(mem,-1,sizeof(mem));
    cout<<dp(0,0,0);
}

// hope to debug successfully