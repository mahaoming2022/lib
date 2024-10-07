#include <bits/stdc++.h>

#define i64 long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define fdn(i,r,l) for(int i=(r);i>=(l);i--)
#define pii pair<int,int>
using namespace std;

typedef long long ll;
typedef double db;
typedef __int128 i128;

int n;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>n;
    vector<int> a(n+1),sum(n+1),upper(n+1);
    rep(i,1,n) cin>>a[i]; 
    rep(r,1,n)
    {
        int l=r-1;
        while(l>0&&a[l]<a[r])
            l=upper[l];
        upper[r]=l;
        sum[l]++,sum[r]--;
    }
    rep(i,1,n)
        sum[i]+=sum[i-1],cout<<sum[i]<<' ';
}