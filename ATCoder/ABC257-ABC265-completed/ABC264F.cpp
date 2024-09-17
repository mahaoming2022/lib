#include <bits/stdc++.h>

#define i64 long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define fdn(i,r,l) for(int i=(r);i>=(l);i--)
#define pii pair<int,int>
using namespace std;

typedef long long ll;
typedef double db;
typedef __int128 i128;

const int N=2024;

const ll inf=1ll<<59;

int n,m;
ll r[N],c[N],mem[N][N][2][2];
bool a[N][N];

ll dp(int i,int j,bool x,bool y)
{
    ll& ans=mem[i][j][x][y];
    if(ans!=-1) return ans;
    ll ans1=inf,ans2=inf;
    if(i>1)
    {
        // 列间转移
        if((a[i][j]^x^y)==(a[i-1][j]^y)) 
            ans1=r[i]*x+dp(i-1,j,0,y);
        else ans1=r[i]*x+dp(i-1,j,1,y);
    }
    if(j>1)
    {
        // 行间转移
        if((a[i][j]^x^y)==(a[i][j-1]^x))
            ans2=c[j]*y+dp(i,j-1,x,0);
        else ans2=c[j]*y+dp(i,j-1,x,1);
    }
    return ans=min(ans1,ans2);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>n>>m;
    rep(i,1,n) cin>>r[i];
    rep(i,1,m) cin>>c[i];
    rep(i,1,n) rep(j,1,m)
    {
        char cc;cin>>cc;
        a[i][j]=cc-'0';
    }
    memset(mem,-1,sizeof(mem));
    mem[1][1][0][0]=0,mem[1][1][1][0]=r[1],mem[1][1][0][1]=c[1],mem[1][1][1][1]=r[1]+c[1];
    ll ans=min(dp(n,m,1,1),min(dp(n,m,1,0),min(dp(n,m,0,1),dp(n,m,0,0))));
    cout<<ans;
}