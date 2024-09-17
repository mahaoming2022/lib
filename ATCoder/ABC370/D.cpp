#include <bits/stdc++.h>

#define i64 long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define fdn(i,r,l) for(int i=(r);i>=(l);i--)
#define pii pair<int,int>
using namespace std;

typedef long long ll;
typedef double db;
typedef __int128 i128;

vector<set<int> > line,col;
int n,m,Q;

void del(int x,int y)
{
    line[x].erase(y);
    col[y].erase(x);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>n>>m>>Q;
    line.resize(n+1),col.resize(m+1);
    rep(i,1,n) rep(j,1,m) line[i].insert(j),col[j].insert(i);
    rep(j,1,Q)
    {
        int x,y;
        cin>>x>>y;
        if(line[x].find(y)!=line[x].end())
        {
            del(x,y);
            continue;
        }
        auto pos1=col[y].lower_bound(x);
        if(pos1!=begin(col[y]))
            del(*(prev(pos1)),y);
        auto pos2=col[y].lower_bound(x);
        if(col[y].lower_bound(x)!=end(col[y]))
            del(*pos2,y);
        auto pos3=line[x].lower_bound(y);
        if(pos3!=begin(line[x]))
            del(x,*(prev(pos3)));
        auto pos4=line[x].lower_bound(y);
        if(line[x].lower_bound(y)!=end(line[x]))
            del(x,*pos4);
    }
    int ans=0;
    rep(i,1,n) ans+=line[i].size();
    cout<<ans;
}

// hope to debug successfully