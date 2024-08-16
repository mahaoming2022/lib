#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define pii pair<int,int>

using namespace std;
typedef long long ll;

const int N=2024;
const int Dx[10]={-1,-1,0,0,1,1};
const int Dy[10]={-1,0,-1,1,0,1};

int n;
bool blk[N][N],vis[N][N];

void dfs(int ox,int oy)
{
    rep(i,0,5)
    {
        int x=ox+Dx[i];
        int y=oy+Dy[i];
        if(!vis[x][y]&&blk[x][y])
        {
            vis[x][y]=1;
            dfs(x,y);
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n;
    vector<pair<int,int> > b;
    rep(i,1,n)
    {
        int xi,yi;
        cin>>xi>>yi;
        xi+=1000,yi+=1000;
        blk[xi][yi]=1;
        b.push_back({xi,yi});
    }
    int cnt=0;
    for(auto i:b)
        if(!vis[i.first][i.second])
        {
            vis[i.first][i.second]=1;
            dfs(i.first,i.second);
            cnt++;
        }
    cout<<cnt;
}