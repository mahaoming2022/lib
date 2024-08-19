#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)

using namespace std;
typedef long long ll;

const int N=2e5+23;
int n,m;
int a[2*N],sum[2*N];
unordered_map<int,int> cnt;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n>>m;
    rep(i,1,n) cin>>sum[i],sum[i+n]=sum[i];
    rep(i,1,2*n) sum[i]+=sum[i-1],sum[i]%=m;
    rep(i,1,n) cnt[sum[i]]++;  
    ll ans=0;
    rep(i,1,n)
    {
        cnt[sum[i]]--; // 弃用
        ans+=cnt[sum[i]]; // 统计
        cnt[sum[i+n]]++; // 启用
    }
    cout<<ans;
}