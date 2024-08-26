#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)

using namespace std;
typedef long long ll;
typedef double db;

int n,m;
map<ll,ll> cnt;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    ll sum=0;
    cin>>n>>m;
    rep(i,1,n){ll tt;cin>>tt;cnt[tt]++;sum+=tt;}
    int l=-1;
    ll ans=0,tot=0,nxt=0;
    bool not_vis=1;
    for(auto i:cnt)
    {
        if(i.first-l>1&&l!=-1)
        {
            ans=max(ans,tot);
            if(not_vis) nxt=tot; // 记录上一段遗留
            not_vis=0;
            tot=0;
        }
        tot+=i.first*i.second;
        l=i.first;
        if(i.first==m-1&&cnt.find(0)!=cnt.end()) ans=max(ans,tot+nxt);
    }
    ans=max(ans,tot);
    cout<<sum-ans;
}

// 参考题解写的，柯西还没太懂