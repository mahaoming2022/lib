#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)

using namespace std;

typedef long long ll;
typedef double db;

const int N=21;

int n,m;
int c[N];
bool vis[N];

void dfs(int d,int lst)
{
    if(d==n+1)
    {
        rep(i,1,n) cout<<c[i]<<' ';
        cout<<endl;
        return ;
    }
    rep(i,1,m) if(!vis[i]&&i>lst)
    {
        vis[i]=1,c[d]=i;
        dfs(d+1,i);
        vis[i]=0;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n>>m;
    dfs(1,0);
}