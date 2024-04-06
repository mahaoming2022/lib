#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;++i)

using namespace std;

const int M=1e4+23;

int t,n,m;
int price[105][105];
int dp[M];

signed main()
{
    ios::sync_with_stdio(false);
    cin>>t>>n>>m;
    rep(i,1,t)
        rep(j,1,n)
            cin>>price[i][j];
    rep(k,1,t-1){
        rep(i,1,m)
            dp[i]=0;
        rep(i,1,n)
            rep(j,price[k][i],m)
                dp[j]=max(dp[j],dp[j-price[k][i]]+price[k+1][i]-price[k][i]);
        m+=dp[m];
    }
    cout<<m;
}