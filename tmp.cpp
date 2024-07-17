#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);++i)

using namespace std;
typedef long long ll;
typedef double db;

const int N=1024;

int n,m,p;
int coin[N][N],cost[N],dp[N];

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n>>m>>p;
    rep(i,1,n) rep(j,1,m) cin>>coin[i][j];
    rep(i,1,n) cin>>cost[i];
    rep(i,1,m) dp[i]=-1<<29;
    rep(i,1,m) rep(j,1,n){
        int sum=0;
    for(int k=1;k<=p&&k<=i;k++){
        int lst=j-k;
        if(lst<=0)
            lst=n+lst%n; 
        sum+=coin[lst][i-k+1];
        dp[i]=max(dp[i],dp[i-k]+sum-cost[lst]);
    }}
    cout<<dp[m];
}