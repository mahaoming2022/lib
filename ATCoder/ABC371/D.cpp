#include <bits/stdc++.h>

#define i64 long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define fdn(i,r,l) for(int i=(r);i>=(l);i--)
#define pii pair<int,int>
using namespace std;

typedef long long ll;
typedef double db;
typedef __int128 i128;

const ll inf=1e9+23;
int n;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>n;
    map<ll,ll> cnt;
    vector<ll> a(n+1),b(n+1);
    rep(i,1,n) cin>>a[i];
    rep(i,1,n) cin>>b[i];
    rep(i,1,n) cnt[a[i]]+=b[i];
    for(auto i=cnt.begin();i!=cnt.end();i++)
        if(i!=cnt.begin())
            (*i).second+=(*prev(i)).second;
    cnt[-inf]=0;
    cnt[inf]=(*cnt.end()).second;
    int Q;cin>>Q;
    while(Q--)
    {
        int l,r;
        cin>>l>>r;
        auto p1=prev(cnt.lower_bound(l)),p2=prev(cnt.upper_bound(r));
        cout<<(*p2).second-(*p1).second<<endl;
    }
}