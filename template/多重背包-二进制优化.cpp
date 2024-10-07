#include <bits/stdc++.h>

#define i64 long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define fdn(i,r,l) for(int i=(r);i>=(l);i--)
#define pii pair<int,int>
using namespace std;

typedef unsigned long long ll;
typedef double db;
typedef __int128 i128;

int n,W;

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>n>>W;
    vector<pair<int,int> > a;
    vector<int> dp(W+1);
    rep(i,1,n)
    {
        int v,w,m;
        cin>>v>>w>>m;
        int c=1;
        for(;m>c;c<<=1)
        {
            m-=c;
            a.push_back({w*c,v*c});
        }
        a.push_back({w*m,v*m});
    }
    for(auto i:a)
        for(int j=W;j>=i.first;j--)
            dp[j]=max(dp[j],dp[j-i.first]+i.second);
    cout<<dp[W]<<endl;
}