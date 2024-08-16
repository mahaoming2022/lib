#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)

using namespace std;
typedef long long ll;
typedef long double db;

const int N=520;

int n,m;
vector<pair<int,int> > D;
queue<pair<int,int>,list<pair<int,int> > > q;
int dp[N][N];bool vis[N][N];

void bfs()
{
    rep(i,1,n) rep(j,1,n) vis[i][j]=0;
    dp[1][1]=0;
    q.push({1,1});
    while(!q.empty())
    {
        int x=q.front().first,y=q.front().second;
        cout<<x<<' '<<y<<endl;
        q.pop();
        if(vis[x][y]) continue;
        vis[x][y]=1;
        for(auto d:D)
        {
            int xx=x+d.first,yy=y+d.second;
            if(xx<1||xx>n||yy<1||yy>n)
                continue;
            dp[xx][yy]=dp[x][y]+1;
            q.push({xx,yy});
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n>>m;
    rep(i,-1000,1000)
        rep(j,-1000,1000)
            if(i*i+j*j==m)
                D.push_back({i,j});
    rep(i,1,n){
        rep(j,1,n)
            cout<<dp[i][j]<<' ';
        cout<<endl;
    }
}