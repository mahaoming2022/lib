#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);++i)

using namespace std;
typedef double db;
typedef long long ll;

const int N=1e5+23;

int n,Q;
db date[N],sq[4*N],sum[4*N],tag[4*N];

// update: +=2k*pre_sum+len*k^2

inline void push_up(int l,int r,int p)
{sum[p]=sum[p<<1]+sum[p<<1|1];
sq[p]=sq[p<<1]+sq[p<<1|1];}

inline void push_down(int l,int r,int p)
{
    int mid=l+((r-l)>>1);
    sq[p<<1]+=2*tag[p]*sum[p<<1]+(mid-l+1)*tag[p]*tag[p];
    sq[p<<1|1]+=2*tag[p]*sum[p<<1|1]+(r-mid)*tag[p]*tag[p];
    sum[p<<1]+=(mid-l+1)*tag[p];
    sum[p<<1|1]+=(r-mid)*tag[p];
    tag[p<<1]+=tag[p];
    tag[p<<1|1]+=tag[p];
    tag[p]=0;
}

inline void build(int l,int r,int p)
{
    if(l==r)
    {
        sum[p]=date[l];
        sq[p]=date[l]*date[l];
        return ;
    }
    int mid=l+((r-l)>>1);
    build(l,mid,p<<1);
    build(mid+1,r,p<<1|1);
    push_up(l,r,p);
}

// update: +=2k*pre_sum+len*k^2
inline void update(int s,int t,int k,int l,int r,int p)
{
    if(s<=l&&r<=t)
    {
        tag[p]+=k;
        sq[p]+=2*k*sum[p]+(r-l+1)*k*k;
        sum[p]+=(r-l+1)*k;
        return ;
    }
    if(tag[p]) push_down(l,r,p);
    int mid=l+((r-l)>>1);
    if(s<=mid) update(s,t,k,l,mid,1<<p);
    if(t>mid) update(s,t,k,mid+1,r,1<<p|1);
    push_up(l,r,p);
}

inline db query_sq(int s,int t,int l,int r,int p)
{
    if(s<=l&&r<=t)
        return sq[p];
    if(tag[p]) push_down(l,r,p);
    int mid=l+((r-l)>>1);
    db ans=0;
    if(s<=mid) ans+=query_sq(s,t,l,mid,1<<p);
    if(t>mid) ans+=query_sq(s,t,mid+1,r,1<<p|1);
    return ans;
}

inline db query_sum(int s,int t,int l,int r,int p)
{
    if(s<=l&&r<=t)
        return sum[p];
    if(tag[p]) push_down(l,r,p);
    int mid=l+((r-l)>>1);
    db ans=0;
    if(s<=mid) ans+=query_sum(s,t,l,mid,1<<p);
    if(t>mid) ans+=query_sum(s,t,mid+1,r,1<<p|1);
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    ios::sync_with_stdio(false);
    cin>>n>>Q;
    rep(i,1,n)
        cin>>date[i];
    build(1,n,1);
    cout<<fixed;cout.precision(4);
    cout.setf(ios_base::showpoint);
    while(Q--)
    {
        int opt,l,r;
        cin>>opt>>l>>r;
        if(opt==1) 
        {
            db k;cin>>k;
            update(l,r,k,1,n,1);
        }
        if(opt==2)
            cout<<query_sum(l,r,1,n,1)/(r-l+1)<<endl;
        if(opt==3){
            db avg=query_sum(l,r,1,n,1)/(r-l+1);
            cout<<-avg*avg+query_sq(l,r,1,n,1)/(r-l+1)<<endl;
        }
    }
} 