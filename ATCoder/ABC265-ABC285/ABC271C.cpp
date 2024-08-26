#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)

using namespace std;

const int N=3e5+24;

int n;
int a[N];
bool vis[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n;
    rep(i,1,n) {cin>>a[i];if(a[i]<=n)vis[a[i]]=1;}
    for(int i=1;n>=0;i++)
    {
        if(vis[i]) n--;
        else n-=2;
        if(n<0){cout<<i-1;return 0;}
    }
}