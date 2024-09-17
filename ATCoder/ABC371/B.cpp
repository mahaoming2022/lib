#include <bits/stdc++.h>

#define i64 long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define fdn(i,r,l) for(int i=(r);i>=(l);i--)
#define pii pair<int,int>
using namespace std;

typedef long long ll;
typedef double db;
typedef __int128 i128;

const int N=114;

bool vis[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    rep(i,1,m)
    {
        int a; char b;
        cin>>a>>b;
        if(vis[a]||(b=='F')) cout<<"No"<<endl;
        else
        {
            vis[a]=1;
            cout<<"Yes"<<endl;
        }
    }
}