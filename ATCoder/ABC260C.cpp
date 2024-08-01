#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)

using namespace std;

typedef long long ll;
typedef double db;

ll n,x,y;

ll dfs(int lev,bool red)
{
    if(lev==1&&!red) return 1;
    else if(lev==1&&red) return 0;
    ll ans=0;
    if(red) ans=dfs(lev-1,1)+x*dfs(lev,0);
    if(!red) ans=dfs(lev-1,1)+y*dfs(lev-1,0);
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n>>x>>y;
    cout<<dfs(n,1);
}