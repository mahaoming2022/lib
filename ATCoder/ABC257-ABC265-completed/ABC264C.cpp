#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)

using namespace std;

typedef long long ll;
typedef double db;

const int N=20;

int w1,h1,w2,h2;
int a[N][N],b[N][N];
bool col[N],line[N];
vector<pair<int,int> > tx,ty;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>w1>>h1;
    rep(i,1,w1) rep(j,1,h1) cin>>a[i][j];
    cin>>w2>>h2;
    rep(i,1,w2) rep(j,1,h2) cin>>b[i][j];
    int sx,sy;
    rep(i,1,w1) rep(j,1,h2)
        if(a[i][j]==b[1][1])
            sx=i,sy=j;
    int fx=1,fy=1;
    rep(i,1,h1)
        if(b[1][fy]==a[sx][i])
            tx.push_back({i,fy}),fy++;
    rep(j,1,w1)
        if(b[fx][1]==a[j][sy])
            ty.push_back({j,fx}),fx++;
    for(auto i:ty) for(auto j:tx){
        if(a[i.first][j.first]==b[i.second][j.second])
        {cout<<"No";return 0;}
    }
    cout<<"Yes";
}