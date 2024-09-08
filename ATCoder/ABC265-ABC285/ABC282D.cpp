// Written by da_ke
// Website: https://mahaoming2022.github.io

#include <bits/stdc++.h>

#define i64 long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define fdn(i,r,l) for(int i=(r);i>=(l);i--)
#define pii pair<int,int>
using namespace std;

typedef long long ll;
typedef double db;
typedef __int128 i128;

int n,m;
ll c0,c1;
vector<vector<int> > linker;
vector<int> col;
vector<bool> vis;

void dfs(int o)
{
    if(col[o]==0) c0++;
    if(col[o]==1) c1++;
    for(auto u:linker[o])
    {
        if(!vis[u])
        {
            vis[u]=1;
            col[u]=col[o]^1;
            dfs(u);
        }
        else if(col[u]==col[o])
        {
            cout<<0<<endl;
            exit(0);
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>n>>m;
    linker.resize(n+1);
    col.resize(n+1);
    vis.resize(n+1,0);
    rep(i,1,m)
    {
        int u,v;
        cin>>u>>v;
        linker[u].push_back(v);
        linker[v].push_back(u);
    }
    ll ans=0,sum=0;
    rep(i,1,n)
        if(!vis[i])
        {
            vis[i]=1,col[i]=1,c0=0,c1=0;
            dfs(i);
            ans+=c0*c1,sum+=(c0+c1)*(n-c0-c1);
        }
    cout<<ans-m+sum/2;
}

// hope to debug successfully