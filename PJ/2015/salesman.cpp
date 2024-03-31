#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define pii pair<int,int>

using namespace std;

const int N=1e5+24;

int n;
pii a[N];
int sum[N],f[N],t[N];

bool cmp(const pii& A,const pii& B)
{
    return A.second>B.second;
}

int main()
{
    freopen("salesman.in","r",stdin);
    freopen("salesman.out","w",stdout);
    cin>>n;
    rep(i,1,n)
        cin>>a[i].first; //s
    rep(i,1,n)
        cin>>a[i].second; //a
    sort(a+1,a+1+n,cmp);
    rep(i,1,n)
    {
        sum[i]=sum[i-1]+a[i].second; //a
        f[i]=max(f[i-1],2*a[i].first); //s
    }
    for(int i=n;i>=1;i--)
        t[i]=max(t[i+1],a[i].second+2*a[i].first);
    rep(i,1,n)
        cout<<max(sum[i]+f[i],sum[i-1]+t[i])<<endl;
}
