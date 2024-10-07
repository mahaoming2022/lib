#include <bits/stdc++.h>

#define i64 long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define fdn(i,r,l) for(int i=(r);i>=(l);i--)
#define pii pair<int,int>
using namespace std;

typedef long long ll;
typedef double db;
typedef __int128 i128;

const int N=1e4+23;
const int K=114;

int n,m,k;
ll dis[N][K]; bool vis[N][K];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
#endif
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>n>>m>>k;
    vector<vector<pair<int,int> > > linker(n+1);
    rep(i,1,m)
    {
        int u,v,w;
        cin>>u>>v>>w;
        linker[u].push_back({v,w});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > q;
    memset(dis,127,sizeof(dis));
    dis[1][0]=0;
    q.push({0,1});
    while(!q.empty())
    {
        int u=q.top().second; ll p=q.top().first;
        q.pop();
        if(vis[u][p%k])
            continue;
        vis[u][p%k]=1;
        for(auto i:linker[u])
        {
            int v=i.first; ll w=i.second;
            ll t;
            if(p>=w) t=p;
            else t=ceil(1.0*(w-p)/k)*k+p;
            if(t+1<dis[v][(t+1)%k])
            {
                dis[v][(t+1)%k]=t+1;
                q.push({t+1,v});
            }
        }
    }
    cout<<((dis[n][0]==1ll<<59)?-1:dis[n][0])<<endl;
}