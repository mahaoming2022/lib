#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;++i)

using namespace std;

const int N=10;

int n;
int dp[N][N][N][N][N];

int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    rep(i,1,n)
    {
        int a,b,c,d,e;
        cin>>a>>b>>c>>d>>e;
        rep(j,1,9){
            dp[(a+j)%10][b][c][d][e]++;
            dp[a][(b+j)%10][c][d][e]++;
            dp[a][b][(c+j)%10][d][e]++;
            dp[a][b][c][(d+j)%10][e]++;
            dp[a][b][c][d][(e+j)%10]++;
            dp[(a+j)%10][(b+j)%10][c][d][e]++;
            dp[a][(b+j)%10][(c+j)%10][d][e]++;
            dp[a][b][(c+j)%10][(d+j)%10][e]++;
            dp[a][b][c][(d+j)%10][(e+j)%10]++;
        }
    }
    int ans=0;
    rep(i,0,9) rep(j,0,9) rep(k,0,9) rep(l,0,9) rep(m,0,9)
        if(dp[i][j][k][l][m]==n) ans++;
    cout<<ans;
}