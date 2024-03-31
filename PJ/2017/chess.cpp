#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int Dx[14]={0, 0,0, 0,1, 1,1,-1,-1,-1,2,-2};
const int Dy[14]={1,-1,2,-2,0,-1,1, 0,-1, 1,0, 0};
const int W[14]= {0, 0,2, 2,0, 2,2, 0, 2, 2,2, 2};

struct node{
    int x,y,w,c;
    bool operator > (const node& A) const
    {
        return (this->w)>(A.w);
    }
};

int m,n;
bool has_color[124][124];
int color[124][124];
int dis[124][124];
bool vis[124][124];

priority_queue<node,vector<node>,greater<node> > q; 

void dijkstra()
{
    for(int i=1;i<=m;++i)
        for(int j=1;j<=m;++j)
            dis[i][j]=1<<30,vis[i][j]=0;
    dis[1][1]=0;
    q.push({1,1,0,color[1][1]});
    while(!q.empty())
    {
        node cur=q.top();
        q.pop();
        int x=cur.x;
        int y=cur.y;
        int w=cur.w;
        int c=cur.c;
        if(vis[x][y])
            continue;
        if(!has_color[x][y])
            continue;
        vis[x][y]=1;
        for(int d=0;d<12;++d)
        {
            int xx=x+Dx[d];
            int yy=y+Dy[d];
            int ww=w+W[d];
            if(!has_color[xx][yy])
                continue;
            if(xx<1||xx>m||yy<1||yy>m)
                continue;
            if(c!=color[xx][yy])
                ww++;
            if(ww<dis[xx][yy])
            {
                dis[xx][yy]=ww;
                q.push({xx,yy,ww,color[xx][yy]});
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("chess.in","r",stdin);
#endif
    cin>>m>>n;
    for(int i=1;i<=n;++i)
    {
        int xi,yi,ci;
        cin>>xi>>yi>>ci;
        color[xi][yi]=ci;
        has_color[xi][yi]=1;
    }
    dijkstra();
    if(!has_color[m][m])
        dis[m][m]=min(dis[m-1][m],dis[m][m-1])+2;
    if(dis[m][m]>=(1<<30))
        dis[m][m]=-1;
    cout<<dis[m][m];
}
