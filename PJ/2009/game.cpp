#include <bits/stdc++.h>

using namespace std;

int coin[1024][1024],cost[1024];
int dp[1024];

int main()
{
    //freopen("in.in","r",stdin);
    int n,m,p;
    cin>>n>>m>>p;
    for(int i=1;i<=n;++i) //road(i-th factory -> i-th road)
        for(int j=1;j<=m;++j) //time
            cin>>coin[i][j];
    for(int i=1;i<=n;++i)
        cin>>cost[i];
    for(int i=1;i<=m;++i)
        dp[i]=-(1<<30);
    for(int i=1;i<=m;++i) //time
        for(int j=1;j<=n;++j) //factory
        {
            int sum=0;
            for(int k=1;k<=i&&k<=p;++k)
            {
                int lst=j-k;
                if(lst<=0)
                    lst=n+lst%n;
                sum+=coin[lst][i-k+1];
                dp[i]=max(dp[i],dp[i-k]+sum-cost[lst]);
            }
        }
    cout<<dp[m];
}
