#include <bits/stdc++.h>

#define i64 long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define fdn(i,r,l) for(int i=(r);i>=(l);i--)
#define pii pair<int,int>
using namespace std;

typedef long long ll;
typedef double db;
typedef __int128 i128;

int n,m,Q;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>n>>m>>Q;
    vector<set<int> > line(n+1),col(m+1);
    rep(i,1,n) rep(j,1,m) line[i].insert(j),col[j].insert(i);
    rep(j,1,Q)
    {
        int x,y;
        cin>>x>>y;
        if(line[x].find(y)!=line[x].end())
        {
            line[x].erase(y),
            col[y].erase(x);
            continue;
        }
        {
            auto pos=line[x].lower_bound(y);
            if(pos!=begin(line[x]))
                line[x].erase(*prev(pos)),
                col[*prev(pos)].erase(x);
        }
        {
            auto pos=line[x].lower_bound(y);
            if(pos!=end(line[x]))
                line[x].erase(*pos),
                col[*pos].erase(x);
        }
        {
            auto pos=col[y].lower_bound(x);
            if(pos!=begin(col[y]))
                line[*prev(pos)].erase(y),
                col[y].erase(*prev(pos));
        }
        {
            auto pos=col[y].lower_bound(x);
            if(pos!=end(col[y]))
                line[*pos].erase(y),
                col[y].erase(*pos);
        }
    }
    int ans=0;
    rep(i,1,n) ans+=line[i].size();
    cout<<ans;
}

// hope to debug successfully