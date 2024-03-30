#include <bits/stdc++.h>

using namespace std;

const int INF=1<<29;

int n,m,r,c,ans=INF;
int a[34][34];
int row[34],s1[34],s2[34][34],dp[24][34];

int main()
{
    cin>>n>>m>>r>>c;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            cin>>a[i][j];
    for(int B=0;B<(1<<n);++B)
    {
        int cnt=0;
        for(int i=0;i<n;++i)
            if(B&(1<<i))
                row[++cnt]=i+1;
        if(cnt!=r)
            continue;
        for(int i=1;i<=m;++i)
        {
            s1[i]=0;
            for(int j=1;j<=cnt-1;++j)
                s1[i]+=abs(a[row[j]][i]-a[row[j+1]][i]);
            for(int k=i+1;k<=m;++k)
            {
                s2[i][k]=0;
                for(int j=1;j<=cnt;++j)
                    s2[i][k]+=abs(a[row[j]][i]-a[row[j]][k]);
            }
        }
        for(int i=0;i<=m;++i)
            for(int j=0;j<=c;++j)
                dp[i][j]=INF;
        dp[0][0]=0;
        for(int i=1;i<=m;++i)
        {
            dp[i][1]=s1[i];
            for(int j=2;j<=c;++j)
            {
                for(int k=1;k<i;++k)
                    dp[i][j]=min(dp[i][j],dp[k][j-1]+s1[i]+s2[k][i]);
            }
            ans=min(ans,dp[i][c]);
        }
    }
    cout<<ans;
}
