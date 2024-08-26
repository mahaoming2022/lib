// #define EXT
#include <bits/stdc++.h>
#ifdef EXT
    #include <bits/extc++.h>
#endif

//define
#define i64 long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define fdn(i,r,l) for(int i=(r);i>=(l);i--)
#define pii pair<int,int>

using namespace std;

// type define
typedef long long ll;
typedef double db;
typedef __int128 i128;

int n,m;
int a[114];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>n>>m;
    rep(i,1,n)
        cin>>a[i];
    rep(i,n-m+1,n)
        cout<<a[i]<<' ';
    rep(i,1,n-m)
        cout<<a[i]<<' ';
}