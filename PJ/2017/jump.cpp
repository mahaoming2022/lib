#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
const int N=5e5+24;
const ll INF=9e17;

int n;
ll d,k;

int dis[N],s[N];
ll dp[N],q[N];

bool check(ll g)
{
    rep(i,1,n)
        dp[i]=-INF;
    memset(q,0,sizeof(q));
    ll fl=max(d-g,(ll)1), fr=d+g;
    dp[0]=0;
    int head=1,tail=0,j=0;
    rep(i,1,n)
    {
        while(j<i&&dis[i]-dis[j]>=fl)
        {
            if(j>-INF)
            {
                while(dp[q[tail]]<=dp[j]&&head<=tail) --tail;
                q[++tail]=j;
            }
            ++j;
        }
        while(dis[i]-dis[q[head]]>fr&&head<=tail) ++head;
        if(head<=tail) dp[i]=dp[q[head]]+s[i];
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
    ios::sync_with_stdio(false);
    cin>>n>>d>>k;
    rep(i,1,n)
        cin>>dis[i]>>s[i];
    int l=0,r=dis[n];
    while(l<r)
    {
        ll mid=(l+r)>>1;
        if(check(mid))
            r=mid;
        else
            l=mid+1;
    }
    cout<<((l==dis[n])?-1:l);
    // cout<<l;
}