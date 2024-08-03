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
    int cnt=0;
    rep(i,100,999)
        if((i/100!=i%10&&i%10!=(i/10)%10)) cnt++;
        cout<<cnt;
};