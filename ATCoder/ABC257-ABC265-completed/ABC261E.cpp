#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)

using namespace std;

typedef long long ll;
typedef double db;

const int N=2e5+24;

int n,c,ans=0;
int o[N],a[N];
bool dp[N][33][2];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n>>c;
    rep(i,1,n) cin>>o[i]>>a[i];
    rep(k,0,1)
        rep(j,0,30){
            dp[0][j][k]=k;
            rep(i,1,n){
            int s=(a[i]>>j)&1;
            if(o[i]==1) dp[i][j][k]=dp[i-1][j][k]&s;
            if(o[i]==2) dp[i][j][k]=dp[i-1][j][k]|s;
            if(o[i]==3) dp[i][j][k]=dp[i-1][j][k]^s;
        }}
    rep(i,1,n)
    {
        int ans=0;
        for(int j=0,s=c;j<=30;j++,s>>=1) 
            ans+=(1<<j)*dp[i][j][s&1];
        cout<<ans<<endl;
        c=ans;
    }
}

// 切记别设最大数位为 32 