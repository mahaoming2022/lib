#include <bits/stdc++.h>

#define i64 long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define fdn(i,r,l) for(int i=(r);i>=(l);i--)
#define pii pair<int,int>
using namespace std;

typedef long long ll;
typedef double db;
typedef __int128 i128;

const int N=4e5+23;

int n,m,k;
int dis[N];
bool vis[N];
vector<pair<int,int> > linker[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>n>>m>>k;
    rep(i,1,m)
    {
        int u,v,w;
        cin>>u>>v>>w;
        if(w==1) linker[u].push_back({v,1}),linker[v].push_back({u,1});
        else linker[u+n].push_back({v+n,1}),linker[v+n].push_back({u+n,1});
    }
    while(k--)
    { 
        int u;cin>>u;
        linker[u].push_back({u+n,0});
        linker[u+n].push_back({u,0});
    }
    deque<int> q;
    rep(i,1,2*n) dis[i]=1<<29;
    dis[1]=0;
    q.push_back(1);
    while(!q.empty())
    {
        int u=q.front();
        q.pop_front();
        for(auto i:linker[u])
        {
            int v=i.first,w=i.second;
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                if(w==0) q.push_front(v);
                else q.push_back(v);
            }
        }
    }
    int ans=min(dis[n],dis[n<<1]);
    cout<<((ans!=1<<29)?ans:-1)<<endl;
}