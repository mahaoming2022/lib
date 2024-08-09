// #include <bits/stdc++.h>
// #define rep(i,l,r) for(int i=l;i<=r;i++)

// using namespace std;

// typedef long long ll;
// typedef double db;

// const ll mod=998244353;
// const int N=114;
// ll dp[N][N][N];

// int n;
// ll a[N];

// int main()
// {
// #ifndef ONLINE_JUDGE
//     freopen("in.in","r",stdin);
//     freopen("out.out","w",stdout);
// #endif
//     cin>>n;
//     rep(i,1,n) cin>>a[i];
//     ll ans=0;
//     rep(i,1,n)
//     {
//         memset(dp,0,sizeof(dp));
//         dp[1][0][0]=1;
//         rep(j,1,n)
//             rep(k,0,i)
//                 rep(r,0,i-1){
//                     dp[j+1][k][r]+=dp[j][k][r];
//                     if(k<i) dp[j+1][k+1][(r+a[j])%i]+=dp[j][k][r],
//                     dp[j+1][k+1][(r+a[j])%i]%=mod;
//                     dp[j+1][k][r]%=mod;
//                 }
//         ans+=dp[n+1][i][0];ans%=mod;
//     }
//     cout<<ans;
// }

// 写废的
#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)

using namespace std;

typedef long long ll;
typedef double db;

const int N=114;
const ll mod=998244353;

int n;
ll a[N],mem[N][N][N];

ll dp(int i,int j,int r,int p)
{
    ll& ans=mem[i][j][r];
    if(ans!=-1) return ans;
    if(j==p) return 1;
    if(j>p) return 0;
    if(i==n+1) return 0;
    ll ans0,ans1;
    ans0=dp(i+1,j,r,p)%mod;
    ans1=dp(i+1,j+1,(r+a[i])%p,p)%mod;
    return ans0+ans1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n;
    rep(i,1,n) cin>>a[i];
    ll ans=0;
    rep(i,1,n)
    {
        rep(i1,0,n) rep(i2,0,n) rep(i3,0,n) mem[i1][i2][i3]=-1;
        ans+=dp(1,0,0,i);ans%=mod;
    }
    cout<<ans;
}