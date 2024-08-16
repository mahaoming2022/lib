#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)

using namespace std;

typedef long long ll;
typedef double db;

const int N=5e5+23;

int n,m,e;
int u[N],v[N],fa[N],t[N],x[N],ans[N],sum=0;
bool vis[N],f[N];

int find(int x)
{
    if(fa[x]==x) return fa[x];
    return fa[x]=find(fa[x]);
}

void un(int x,int y)
{
    int fx=find(x),fy=find(y);
    if(fx==fy) return ;
    if(vis[fx]!=vis[fy]) sum+=t[fx]+t[fy];
    fa[fx]=fy,vis[fy]|=vis[fx];
    if(vis[fy]) t[fy]=0;
    else t[fy]+=t[fx];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n>>m>>e;
    rep(i,1,n+m) fa[i]=i;
    rep(i,1,n) t[i]=1;
    rep(i,n+1,n+m) vis[i]=1;
    rep(i,1,e) cin>>u[i]>>v[i];
    int Q;cin>>Q;
    rep(i,1,Q)
    {
        cin>>x[i];
        f[x[i]]=1;
    }
    rep(i,1,e)
        if(!f[i])
            un(u[i],v[i]);
    for(int i=Q;i>=1;i--)
        ans[i]=sum,un(u[x[i]],v[x[i]]);
    rep(i,1,Q) cout<<ans[i]<<endl;
}