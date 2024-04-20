#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define pii pair<int,int>

using namespace std;
typedef long long ll;

const int N=2e5+23;

int n,Q;
ll a[N],sum[4*N],mi[4*N],tag[4*N];

inline void build(int l,int r,int p)
{
    int lc=p<<1,rc=p<<1|1,mid=l+(r-l)/2;
    if(l==r){
        sum[p]=a[l];
        mi[p]=a[l];
        return ;
    }
    build(l,mid,lc);build(mid+1,r,rc);
    sum[p]=sum[lc]+sum[rc];
    mi[p]=min(mi[lc],mi[rc]);
}

inline void push_down(int l,int r,int p)
{
    int lc=p<<1,rc=p<<1|1,mid=l+(r-l)/2;
    sum[lc]+=tag[p]*(mid-l+1);
    sum[rc]+=tag[p]*(r-mid);
    mi[lc]+=tag[p],mi[rc]+=tag[p];
    tag[lc]+=tag[p],tag[rc]+=tag[p];
    tag[p]=0;
}

inline void update(int s,int t,int l,int r,int v,int p)
{
    int lc=p*2,rc=p*2+1;
    if(s<=l&&r<=t)
    {
        sum[p]+=v*(r-l+1);
        mi[p]+=v,tag[p]+=v;
        return;
    }
    if(tag[p]) push_down(l,r,p);
    int mid=l+(r-l)/2;
    if(s<=mid) update(s,t,l,mid,v,lc);
    if(t>mid) update(s,t,mid+1,r,v,rc);
    sum[p]=sum[lc]+sum[rc];
    mi[p]=min(mi[lc],mi[rc]);
}

inline ll query_min(int s,int t,int l,int r,int p)
{
    int lc=p<<1,rc=p<<1|1;  
    if(s<=l&&r<=t) return mi[p]; // [l,r] in [s,t]
    if(tag[p]) push_down(l,r,p);
    int mid=l+(r-l)/2;
    ll ans=1ll<<59;
    if(s<=mid) ans=min(ans,query_min(s,t,l,mid,lc));
    if(t>mid) ans=min(ans,query_min(s,t,mid+1,r,rc));
    return ans;
}

inline ll query_sum(int s,int t,int l,int r,int p)
{
    int lc=p<<1,rc=p<<1|1;  
    if(s<=l&&r<=t) return sum[p];
    if(tag[p]) push_down(l,r,p);
    int mid=l+(r-l)/2;
    ll ans=0;
    if(s<=mid) ans+=query_sum(s,t,l,mid,lc);
    if(t>mid) ans+=query_sum(s,t,mid+1,r,rc);
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n>>Q;
    rep(i,1,n)
        cin>>a[i];
    build(1,n,1);
    while(Q--)
    {
        char opt;
        cin>>opt;
        if(opt=='P'){
            ll l,r,z;
            cin>>l>>r>>z;
            update(l,r,1,n,z,1);
        }
        if(opt=='M'){
            ll l,r;cin>>l>>r;
            cout<<query_min(l,r,1,n,1)<<endl;
        }
        if(opt=='S'){
            ll l,r;cin>>l>>r;
            cout<<query_sum(l,r,1,n,1)<<endl;
        }
    }
}