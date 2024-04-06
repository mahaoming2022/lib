#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;

const int N=1e5+24;

int n,m,Q;
vector<int> linker[N];
queue<pair<int,int> > q;
int dis[N][2]; // 0 ou ; 1 ji

void bfs()
{
    while(!q.empty()) q.pop();
    rep(i,1,n)
        dis[i][0]=dis[i][1]=1<<29;
    dis[1][0]=0;
    for(auto i:linker[1]){
        dis[i][1]=1;
        q.push(make_pair(i,1));
    }
    while(!q.empty())
    {
        int u=q.front().first,d=q.front().second;
        q.pop();
        for(auto v:linker[u])
        {
            if(d&1&&d+1<dis[v][0])
            {
                dis[v][0]=d+1;
                q.push(make_pair(v,d+1));
            }
            if(!(d&1)&&d+1<dis[v][1])
            {
                dis[v][1]=d+1;
                q.push(make_pair(v,d+1));
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("work.in","r",stdin);
    freopen("work.out","w",stdout);
#endif
    cin>>n>>m>>Q;
    rep(i,1,m)
    {
        int u,v;
        cin>>u>>v;
        linker[u].push_back(v);
        linker[v].push_back(u);
    }
    bfs();
    while(Q--)
    {
        int a,l;
        cin>>a>>l;
        if(l&1)
            cout<<((l>=dis[a][1])?"Yes":"No")<<endl;
        else
            cout<<((l>=dis[a][0])?"Yes":"No")<<endl;
    }
}