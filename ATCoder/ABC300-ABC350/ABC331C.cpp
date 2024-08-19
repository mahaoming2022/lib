#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)

using namespace std;
typedef long long ll;
typedef double db;

const int N=2e5+23;
const int M=1e6+23;

int n;
ll a[N],cnt[M];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif  
    cin>>n;
    rep(i,1,n) cin>>a[i],cnt[a[i]-1]+=a[i];
    for(int i=M-2;i>=1;i--)
        cnt[i]+=cnt[i+1];
    rep(i,1,n) cout<<cnt[a[i]]<<' ';
}