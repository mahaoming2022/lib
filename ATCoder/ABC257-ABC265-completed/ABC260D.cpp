#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)

using namespace std;

typedef long long ll;
typedef double db;

const int N=2e5+23;

int n,k;
int ans[N];
map<int,stack<int> > c; // top->stack

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n>>k;
    rep(i,1,n)
    {
        int p;cin>>p;
        auto pos=c.upper_bound(p);
        if(pos!=c.end()) // 找到
        {swap(c[p],pos->second);c.erase(pos);}
        c[p].push(p);
        if(c[p].size()==k)
        {
            while(!c[p].empty()){ans[c[p].top()]=i;c[p].pop();}
            c.erase(p);
        }
    }
    rep(i,1,n) cout<<(ans[i]?ans[i]:-1)<<endl;
}