#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)

using namespace std;

const int N=520;

int n,m;
char buf[N][N];
bool vis[N][N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n>>m;
    rep(i,1,n) rep(j,1,m)
        cin>>buf[i][j];
    int x=1,y=1;
    while(!vis[x][y])
    {
        bool f=0;
        vis[x][y]=1;
        if(buf[x][y]=='L'&&y-1>=1&&!f) y--,f=1;
        if(buf[x][y]=='R'&&y+1<=m&&!f) y++,f=1;
        if(buf[x][y]=='U'&&x-1>=1&&!f) x--,f=1;
        if(buf[x][y]=='D'&&x+1<=n&&!f) x++,f=1;
        if(!f){cout<<x<<' '<<y;return 0;}
    }
    cout<<-1;
}