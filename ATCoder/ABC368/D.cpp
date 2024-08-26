#include <bits/stdc++.h>
#define i64 long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define fdn(i,r,l) for(int i=(r);i>=(l);i--)
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef double db;
typedef __int128 i128;

const int N=2e5+23;

int n,m;
bool h[N],vis[N];
vector<int> linker[N];

void dfs(int o)
{
    for(auto i:linker[o])
        if(!vis[i])
        {
            vis[i]=1;
            dfs(i);
            h[o]|=h[i];
        }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    // ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>n>>m;
    rep(i,1,n-1)
    {
        int u,v;
        cin>>u>>v;
        linker[u].push_back(v);
        linker[v].push_back(u);
    }
    int s=0;
    rep(i,1,m) {
        int tmp;
        cin>>tmp;
        if(!s) s=tmp;
        h[tmp]=1;
    }
    vis[s]=1;
    dfs(s);
    int ans=0;
    rep(i,1,n) if(h[i]) ans++;
    cout<<ans;
}