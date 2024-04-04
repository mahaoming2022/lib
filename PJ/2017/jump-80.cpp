#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
const int N=5e5+24;
const ll INF=1<<29;

int n;
ll d,k;

int dis[N],s[N];
ll dp[N];

bool check(ll g)
{
    rep(i,1,n)
        dp[i]=-INF;
    ll fl=max(d-g,(ll)1), fr=d+g;
    dp[0]=0;
    rep(i,1,n)
        for(int j=i-1;j>=0;j--) // from j to i
        {
            ll d=dis[i]-dis[j];
            if(d<fl)
                continue;
            if(d>fr)
                break;
            dp[i]=max(dp[i],dp[j]+s[i]);
            if(dp[i]>=k)
                return true;
        }
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("jump.in","r",stdin);
    freopen("jump.out","w",stdout);
#endif
    cin>>n>>d>>k;
    rep(i,1,n)
        cin>>dis[i]>>s[i];
    int l=0,r=dis[n];
    while(l<r)
    {
        ll mid=l+(r-l)/2;
        if(check(mid))
            r=mid;
        else
            l=mid+1;
    }
    cout<<((l==dis[n])?-1:l);
    // cout<<l;
}