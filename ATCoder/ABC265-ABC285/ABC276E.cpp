#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)

using namespace std;
typedef long long ll;
typedef double db;

const int N=1e6+23;
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};

int h,w,sx,sy;
vector<vector<char> > buf;
vector<vector<bool> > vis;

void dfs(int ox,int oy,int len)
{
    // cout<<ox<<' '<<oy<<endl;
    // if(ox==sx&&oy==sy&&len>=4)
    // {
    //     cout<<"Yes";
    //     exit(0);
    // }
    rep(i,0,3)
    {
        int x=ox+dx[i],y=oy+dy[i];
        if(x<1||x>h||y<1||y>w||buf[x][y]=='#') continue;
        if(x==sx&&y==sy&&len>=3)
        {
            cout<<"Yes";
            exit(0);
        }
        if(vis[x][y]) continue;
        vis[x][y]=1;
        dfs(x,y,len+1);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif  
    cin>>h>>w;
    buf.resize(h+1);
    vis.resize(h+1);
    rep(i,1,h)
    {
        buf[i].resize(w+1);
        vis[i].resize(w+1,0);
        rep(j,1,w)
        {
            cin>>buf[i][j];
            if(buf[i][j]=='S')
                sx=i,sy=j;
        }
    }
    vis[sx][sy]=1;
    dfs(sx,sy,0);
    cout<<"No";
}

// 这道题很Tang，H*W<=1e6，经历过 2023 年春测的都知道应该用 vector。
// 题解采用的处理方式值得借鉴。
// 本代码就是用这种方法的。