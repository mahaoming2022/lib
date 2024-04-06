#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxn=1e5+24;
const ll INF=2LL<<60;
ll c[maxn];

struct info{
    int p;
    ll v;
};

ll _abs(ll a){
    if(a>=0)
        return a;
    else
        return -a;
}

int main(){
    int n,m,i,p1;
    ll s1,s2;
    cin>>n;
    for(i=1;i<=n;++i)
        scanf("%lld",&c[i]);
    cin>>m>>p1>>s1>>s2;
    ll suml=0,sumr=0;
    for(i=1;i<m;++i){
        if(i==p1)
            suml+=1LL*(m-i)*s1;
        suml+=1LL*(m-i)*c[i];
    }
    for(i=m+1;i<=n;++i){
        if(i==p1)
            sumr+=1LL*(i-m)*s1;
        sumr+=1LL*(i-m)*c[i];
    }
    int l,r;
    ll tmp1,tmp2;
    info ans;ans.p=0,ans.v=INF;
    if(suml>sumr)
        l=m,r=n,
        tmp1=sumr,tmp2=suml;
    else
        l=1,r=m,
        tmp1=suml,tmp2=sumr;
    for(i=l;i<=r;++i){
        ll va=_abs(1LL*tmp2-(1LL*tmp1+1LL*_abs(m-i)*s2));
        if(va<ans.v)
            ans.p=i,ans.v=va;
    }
    cout<<ans.p;
    return 0;
}