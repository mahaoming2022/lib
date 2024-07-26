#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)

using namespace std;

typedef long long ll;
typedef double db;

const int N=3356;

int n;
ll sx,sy,tx,ty,r[N];
pair<ll,ll> a[N];
bool linker[N][N],vis[N],s[N],t[N],f=0;

inline void dfs(int o)
{
    vis[o]=1;
    if(t[o]) f=1;
    for(int i=1;i<=n;++i)
        if(linker[o][i]&&!vis[i])
            dfs(i);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n>>sx>>sy>>tx>>ty;
    rep(i,1,n){ 
        cin>>a[i].first>>a[i].second>>r[i];
        if(sx*sx+sy*sy==r[i]*r[i])
            s[i]=1;
        if(tx*tx+ty*ty==r[i]*r[i])
            t[i]=1;
    }
    rep(i,1,n) rep(j,1,n) if(i!=j)
    {
        ll d=(a[i].first-a[j].first)*(a[i].first-a[j].first)+(a[i].second-a[j].second)*(a[i].second-a[j].second);
        if(d>=(r[i]+r[j])*(r[i]+r[j])||d==(r[i]-r[j])*(r[i]-r[j]))
            linker[i][j]=1;
        else linker[i][j]=0;
    }
    bool ans=0;
    rep(i,1,n) if(s[i]){
        dfs(1); 
        if(f) ans=1;
    }
    cout<<(ans?"Yes":"No");
} 