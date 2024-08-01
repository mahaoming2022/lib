// #define EXT
#include <bits/stdc++.h>
#ifdef EXT
    #include <bits/extc++.h>
#endif

#define i64 long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define fdn(i,r,l) for(int i=(r);i>=(l);i--)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef double db;
typedef __int128 i128;

const int INF=1<<29;
const ll INFL=1ll<59;

const int N=1e5+23;

int n,q;
int a[N];

inline bool check(int b,int k,int len)
{
    int o1=upper_bound(a+1,a+1+n,b+len)-a;
    int o2=lower_bound(a+1,a+1+n,b-len)-a;
    return (o1-o2>=k);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("in.out","w",stdout);
#endif
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>n>>q;
    rep(i,1,n) cin>>a[i];
    sort(a+1,a+1+n);
    rep(i,1,q)
    {
        int b,k;
        cin>>b>>k;
        int l=-1,r=1e9;
        while(l+1<r)
        {
            int mid=l+((r-l)>>1);
            if(check(b,k,mid))
                r=mid;
            else l=mid;
        }
        cout<<r<<endl;
    }
}