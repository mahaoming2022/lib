#include <bits/stdc++.h>

#define i64 long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define fdn(i,r,l) for(int i=(r);i>=(l);i--)
#define pii pair<int,int>
using namespace std;

typedef long long ll;
typedef double db;
typedef __int128 i128;

const int N=10;

int n,eg,eh,ans=1<<29;
bool g[N][N],h[N][N],vis[N][N];
int a[N][N];



int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>n>>eg;
    rep(i,1,eg)
    {
        int u,v;
        cin>>u>>v;
        g[u][v]=1,g[v][u]=1;
    }
    cin>>eh;
    rep(i,1,eh)
    {
        int u,v;
        cin>>u>>v;
        h[u][v]=1,h[v][u]=1;
    }
    
}