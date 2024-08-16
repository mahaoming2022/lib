#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)

using namespace std;
typedef long long ll;
typedef double db;

int n,a,b;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n>>a>>b;
    if(a>b) swap(a,b);
    a+=n-b-a;
    if(a>b) cout<<"No";
    else cout<<"Yes";
}