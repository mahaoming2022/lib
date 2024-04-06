#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;

const int mT=4e6+100+24;

int n,m;
int t[mT],cnt[mT],sum[mT];
int f[mT];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("bus20.in","r",stdin);
    freopen("bus20.out","w",stdout);
#endif
    ios::sync_with_stdio(false);
    int t=0;
    cin>>n>>m;
    rep(i,1,n)
    {
        int ti;
        cin>>ti;
        t=max(t,ti);
        cnt[ti]++;
        sum[ti]+=ti;
    }
    rep(i,1,t+m-1)
    {
        cnt[i]+=cnt[i-1];
        sum[i]+=sum[i-1];
    }
    //f(i)=min{f(j)+i*[cnt(i)-cnt(j)]-[sum(i)-sum(j)]}
    rep(i,0,t+m-1)
    {
        f[i]=cnt[i]*i-sum[i];
        rep(j,max(i-2*m,0),i-m)
            f[i]=min(f[i],f[j]+i*(cnt[i]-cnt[j])-(sum[i]-sum[j]));
    }
    int ans=1<<29;
    rep(i,t,t+m-1)
        ans=min(ans,f[i]);
    cout<<ans;
}

// O(tm)