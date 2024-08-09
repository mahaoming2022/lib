#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)

using namespace std;
typedef long long ll;

const int N=1e5+23;

int n,d,cnt=0;
ll t[N],s[N],o[N],v[N];

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    rep(i,1,n-1)
        cin>>t[i];
    rep(i,2,n)
        s[i]=s[i-1]+t[i-1];
    ll mi=1ll<<59;
    rep(i,1,n)
    {
        cin>>v[i];
        if(i==n) v[i]=0;
        if(v[i]<mi) o[++cnt]=i,mi=v[i];
    }
    ll ans=0,l=0;
    rep(i,1,cnt-1){
        ll p=s[o[i+1]]-s[o[i]];
        ll q=ceil(1.0*(p-l)/d);
        ans+=q*v[o[i]];
        l=l+q*d-p;
    }
    cout<<ans;
}

// 1->s1->2->s2->3
// 0------s1-----s1+s2