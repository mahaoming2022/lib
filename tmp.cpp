// #define EXT
#include <bits/stdc++.h>
//define
#define i64 long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define fdn(i,r,l) for(int i=(r);i>=(l);i--)
#define pii pair<int,int>

using namespace std;

// type define
typedef long long ll;
typedef double db;
typedef __int128 i128;

const int N=1e6+23;

int n,a[N],f[N],g[N];
vector<int> linker[N];

inline int dfs(int u,int d)
{
    f[u]=1<<30;
    g[u]=d-a[u]+1;
    int ans=0;
    for(auto i:linker[u])
    {
        ans+=dfs(i,d+1);
        f[u]=min(f[u],f[i]);
        g[u]=min(g[u],g[i]);
    }
    if(f[u]>d)
        ans++,f[u]=g[u];
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>n;
    rep(i,1,n-1){int x,y;cin>>x>>y;linker[x].push_back(y);}
    rep(i,1,n) cin>>a[i];
    cout<<dfs(1,1);
}