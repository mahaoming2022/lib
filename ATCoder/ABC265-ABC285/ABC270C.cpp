#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define pii pair<int,int>

using namespace std;
typedef long long ll;

const int N=2e5+23;

int n,x,y;
vector<int> linker[N];
int v[N];bool vis[N];

void dfs(int i,int o)
{
    if(o==y)
    {
        for(int j=1;j<i;j++)
            cout<<v[j]<<' ';
        exit(0);
    }
    for(auto j:linker[o])
        if(!vis[j])
        {
            vis[j]=1;
            v[i]=j;
            dfs(i+1,j);
        }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n>>x>>y;
    rep(i,1,n-1)
    {
        int ui,vi;
        cin>>ui>>vi;
        linker[ui].push_back(vi);
        linker[vi].push_back(ui);
    }
    vis[x]=1;cout<<x<<' ';
    dfs(1,x);
}