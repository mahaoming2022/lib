#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)

using namespace std;
typedef long long ll;
typedef double db;

const int N=2e5+2;

int n;
bool vis[2*N];
int val[2*N];
vector<int> linker[2*N];
map<int,int> vis1;

void dfs(int o)
{
    for(auto i:linker[o])
        if(!vis[i])
        {
            vis[i]=1;
            dfs(i);
        }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif  
    cin>>n;
    int cnt=0;
    rep(i,1,n)
    {
        int u,v,vu,vv;
        cin>>vu>>vv;
        if(vis1[vu]) u=vis1[vu];
        else u=++cnt,vis1[vu]=u,val[u]=vu;
        if(vis1[vv]) v=vis1[vv]; 
        else v=++cnt,vis1[vv]=v,val[v]=vv;
        linker[u].push_back(v);
        linker[v].push_back(u);
    }
    dfs(vis1[1]);
    int ans=1;
    rep(i,1,cnt) if(vis[i]) ans=max(ans,val[i]);
    cout<<ans;
}

// 1. 要开 2 倍空间
// 2. 注意 n 非 cnt,cnt 才是图点总数。