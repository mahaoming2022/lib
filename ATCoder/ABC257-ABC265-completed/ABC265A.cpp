#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;++i)

using namespace std;

int n,x,y;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>x>>y>>n;
    if(3*x<y)
        cout<<x*n;
    else cout<<y*(n/3)+x*(n%3);
}