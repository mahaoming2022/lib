#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)

using namespace std;

typedef long long ll;
typedef double db;

const int N=2e5+23;

int n;
pair<int,int> a[N];

inline bool cmp(pair<int,int> A,pair<int,int> B)
{return A.first>B.first;}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n;
    rep(i,1,n){cin>>a[i].first;a[i].second=i;};
    sort(a+1,a+1+n,cmp);
    cout<<a[2].second;
}