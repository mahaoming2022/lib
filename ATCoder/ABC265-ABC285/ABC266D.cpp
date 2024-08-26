#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define pii pair<int,int>

using namespace std;
typedef long long ll;

const int N=1e5+23;

int n;
ll T=0,t[N],x[N],v[N],mem[N][10];
ll p[N][10];

ll dp(int i,int j) // i time, j pos
{
    if(i==T+1) return 0;
    ll& ans=mem[i][j];
    if(ans!=-1) return ans;
    ll ans0=0,ansl=0,ansr=0;
    ans0=p[i][j]+dp(i+1,j);
    if(j-1>=0) ansl=p[i][j]+dp(i+1,j-1);
    if(j+1<=4) ansr=p[i][j]+dp(i+1,j+1);
    return ans=max(ans0,max(ansl,ansr));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n;
    rep(i,1,n)
        cin>>t[i]>>x[i]>>v[i],p[t[i]][x[i]]+=v[i];
    T=t[n];
    memset(mem,-1,sizeof(mem));
    cout<<dp(0,0);
}