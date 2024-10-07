#include <bits/stdc++.h>

#define i64 long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define fdn(i,r,l) for(int i=(r);i>=(l);i--)
#define pii pair<int,int>
using namespace std;

typedef unsigned long long ll;
typedef double db;
typedef __int128 i128;

ll n,m,c,k;

ll has_bit=0,has_limit=0;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("zoo.in","r",stdin);
    freopen("zoo.out","w",stdout);
#endif
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>n>>m>>c>>k;
    rep(i,1,n)
    {
        ll a; cin>>a;
        has_bit|=a;
    }
    rep(i,1,m)
    {
        ll p,q; cin>>p>>q;
        has_limit|=(1ull<<p);
    }
    ll ans=0;
    rep(i,0,k-1)
        ans+=!((has_limit>>i)&1)||((has_bit>>i)&1);
    if(n==0&&ans==64) // sb 题目，判了就行，无需理解
    {
        puts("18446744073709551616");
        return 0;
    }
    else if(ans==64)
        cout<<-n<<endl;
    else cout<<(1ull<<ans)-n;
}