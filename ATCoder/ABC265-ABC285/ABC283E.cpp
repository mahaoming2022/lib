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

const int N=1e3+24;
const int Dx[5]={0,0,-1,1};
const int Dy[5]={1,-1,0,0};

int n,m;
int a[N][N];
int dp[N][2][2][2],t[3][N];

bool check(int i,int j,int k,int l)
{
    // i-2,i-1,i
    // 0,1,2
    rep(o,1,m)
    {
        if(i>=3) t[0][o]=a[i-2][o]^l;
        else t[0][o]=-1;
    }
    rep(o,1,m)
        t[1][o]=a[i-1][o]^k;
    rep(o,1,m)
    {
        if(i<=n) t[2][o]=a[i][o]^j;
        else t[2][o]=-1;
    }
    rep(o,1,m)
    {
        bool tag=0;
        rep(D,0,3)
        {
            int x=1+Dx[D],y=o+Dy[D];
            if(y<1||y>m||t[x][y]==-1) continue;
            if(t[1][o]==t[x][y]) tag=1;
        }
        if(!tag) return 0;
    }
    return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>n>>m;
    rep(i,1,n) rep(j,1,m) cin>>a[i][j];
    rep(i,0,n) rep(j,0,1) rep(k,0,1) rep(l,0,1) dp[i][j][k][l]=1<<29;
    dp[1][0][0][0]=0,dp[1][1][0][0]=1;
    rep(i,2,n) rep(j,0,1) rep(k,0,1) rep(l,0,1)
        if(check(i,j,k,l))
            dp[i][j][k][l]=min(dp[i][j][k][l],min(dp[i-1][k][l][1],dp[i-1][k][l][0])+j);
    int ans=1<<29;
    rep(i,0,1) rep(j,0,1) rep(k,0,1)
        if(check(n+1,0,i,j))
            ans=min(ans,dp[n][i][j][k]);
    cout<<(ans!=(1<<29)?ans:-1);
}

// hope to debug successfully