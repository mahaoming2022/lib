#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)

using namespace std;
typedef long long ll;
typedef double db;

const int N=4e5+23;

int n;
int lc[N],rc[N],d[N];

void dfs(int o,int dis)
{
    d[o]=dis;
    if(lc[o])dfs(lc[o],dis+1),dfs(rc[o],dis+1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif  
    int n;
    cin>>n;
    rep(i,1,n)
    {
        int ai;cin>>ai;
        lc[ai]=2*i;
        rc[ai]=2*i+1;
    }
    dfs(1,0);
    rep(i,1,2*n+1)
        cout<<d[i]<<endl;
}

// 注意开大数组