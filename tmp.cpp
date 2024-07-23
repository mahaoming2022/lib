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
#ifdef EXT
    typedef unsigned int ui;
    typedef unsigned long long ull;
    typedef long double ldb;
#endif

const int N=1e6+23;

int h,w,y,n=0;
int a[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    // freopen("tmp.out","w",stdout);
#endif  
    cin>>h>>w>>y;
    rep(i,1,h) rep(j,1,w)
        cin>>a[++n];
    sort(a+1,a+1+n);
    int lev=0,pre=0;
    int ans=n;
    rep(i,1,y)
    {
        lev++;
        int pos=lower_bound(a+1,a+1+n,lev)-a;
        ans-=pos-pre; 
        cout<<ans-(pos-pre)<<endl;
        pre=pos;
    }
}