#include<bits/stdc++.h>

using namespace std;

int n,m;
int a[1024],b[1024];
int linker[1023][1024];
int mem[1023];
bool vis[1024];

int dp(int u)
{
    int& ans=mem[u];
    if(ans!=-1)
        return ans;
    ans=0;
    for(int v=1;v<=n;++v)
        if(linker[u][v])
            ans=max(ans,dp(v)+1);
    return ans;
}

int main()
{
    freopen("level.in","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        memset(vis,0,sizeof(vis));
        int si;
        cin>>si;
        for(int j=1;j<=si;j++)
        {
            cin>>a[j];
            vis[a[j]]=1;
        }
        int ti=0;
        for(int j=a[1];j<=a[si];++j)
            if(!vis[j])
                b[++ti]=j;
        for(int u=1;u<=si;++u)
            for(int v=1;v<=ti;++v)
                linker[a[u]][b[v]]=1;
    }
    memset(mem,-1,sizeof(mem));
    int ans=0;
    for(int i=1;i<=n;++i)
        ans=max(ans,dp(i));
    cout<<ans+1;
}
