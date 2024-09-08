// Written by da_ke
// Website: https://mahaoming2022.github.io

#include <bits/stdc++.h>

#define i64 long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define fdn(i,r,l) for(int i=(r);i>=(l);i--)
#define pii pair<int,int>
using namespace std;

typedef long long ll;
typedef double db;
typedef __int128 i128;

int n;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>n;
    vector<pair<int,char> > a(n+1);
    rep(i,1,n)
        cin>>a[i].first>>a[i].second;
    int ans=1<<29;
    rep(i,1,100)
        rep(j,1,100)
        {
            int tans=0;
            int nl=i,nr=j;
            rep(i,1,n)
            {
                if(a[i].second=='L')
                    tans+=abs(a[i].first-nl),nl=a[i].first;
                if(a[i].second=='R')
                    tans+=abs(a[i].first-nr),nr=a[i].first;
            }
            ans=min(ans,tans);
        }
    cout<<ans;
}

// hope to debug successfully