#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;

const int N=1e6+25;

int n;
int v[N],lc[N],rc[N];
int sz[N];

inline void dfs(int u)
{
    sz[u]=1;
    if(lc[u]!=-1){
        dfs(lc[u]);
        sz[u]+=sz[lc[u]];
    }
    if(rc[u]!=-1){
        dfs(rc[u]);
        sz[u]+=sz[rc[u]];
    }
}

inline bool check(int l,int r)
{
    if(l==-1&&r==-1)
        return 1;
    if(l==-1||r==-1)
        return 0;
    if(v[l]!=v[r])
        return 0;
    return check(lc[l],rc[r])&&check(rc[l],lc[r]);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
#endif
    cin>>n;
    rep(i,1,n)
        cin>>v[i];
    rep(i,1,n)
        cin>>lc[i]>>rc[i];
    dfs(1);
    int ans=0;
    rep(i,1,n)
        if(check(lc[i],rc[i]))
            ans=max(ans,sz[i]);
    cout<<ans;
}