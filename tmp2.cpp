#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)

using namespace std;
typedef long long ll;
typedef double db;

const int N=20;
const db INF=1e9+24;

int n;
db x[N],y[N],mem[N][1<<N];
bool vis[N][1<<N];

db edst(db x1,db y1,db x2,db y2)
{
    return (db)(sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
}

db dp(int i,int k)
{
	if(mem[i][k]!=0.0) return mem[i][k];
	db Ans=INF;
    if(k==0) return mem[i][k]=edst(x[i],y[i],0,0);
    vis[i][k]=1;
    rep(j,1,n)
    {
        if((k&(1<<(j-1)))==0) continue;
        Ans=min(Ans,edst(x[i],y[i],x[j],y[j])+dp(j,k-(1<<(j-1))));
    }
    return mem[i][k]=Ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    ios::sync_with_stdio(false);
    cin>>n;
    rep(i,1,n) cin>>x[i]>>y[i];
    db ans=INF;
    rep(i,1,n) ans=min(ans,dp(i,(1<<n)-1-(1<<(i-1))));
   printf("%.2lf\n",ans);
}
