#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;

const int N=1e3+24;
const ll INF=1ll<<59;

int n,m;
ll a[N][N],mem[N][N][2];

inline ll dp(int i,int j,bool d)
{
    ll& ans=mem[i][j][d];
    if(i==1&&j==1)
        return a[i][j];
    if(i<1||i>n||j<1||j>m)
        return -INF;
    if(ans!=-INF)
        return ans;
    if(d==0)
    {
        ans=max(ans,max(dp(i,j-1,0),dp(i,j-1,1))+a[i][j]);
        ans=max(ans,dp(i+1,j,0)+a[i][j]);
    }
    if(d==1)
    {
        ans=max(ans,max(dp(i,j-1,0),dp(i,j-1,1))+a[i][j]);
        ans=max(ans,dp(i-1,j,1)+a[i][j]);
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n>>m;
    rep(i,1,n)
        rep(j,1,m){
            mem[i][j][0]=mem[i][j][1]=-INF;
            cin>>a[i][j];
        }
    cout<<dp(n,m,1);
}