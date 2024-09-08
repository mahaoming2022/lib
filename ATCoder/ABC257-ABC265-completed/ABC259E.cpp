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

const int N=2e5+23;

int n;
unordered_map<int,int> ps[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>n;
    map<int,pair<int,int> > ln;
    set<vector<pair<int,int> > > ans;
    rep(i,1,n)
    {
        int t;cin>>t;
        while(t--)
        {
            int e,x;
            cin>>e>>x;
            ps[i][e]=x;
            if(x>=min(ln[e].first,ln[e].second))
            {
                if(ln[e].first>ln[e].second)
                    ln[e].second=x;
                else ln[e].first=x;
            }
        }
    }
    int cnt=0;
    rep(i,1,n)
    {
        vector<pair<int,int> > ans1;
        // e^x
        for(auto t:ps[i])
        {
            int e=t.first,x=t.second;
            if(x==max(ln[e].first,ln[e].second)&&x>min(ln[e].first,ln[e].second))
                ans1.push_back({e,x-ln[e].first});
        }
        int t=ans.size();
        ans.insert(ans1);
        if(ans.size()>t) cnt++;
    }
    cout<<cnt;
}

// hope to debug successfully