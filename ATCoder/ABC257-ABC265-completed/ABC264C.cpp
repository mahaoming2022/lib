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

const int N=24;

int h1,w1,h2,w2;
int a[N][N],b[N][N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>h1>>w1;
    rep(i,1,h1) rep(j,1,w1) cin>>a[i][j];
    cin>>h2>>w2;
    rep(i,1,h2) rep(j,1,w2) cin>>b[i][j];
    rep(i,0,1<<h1)
        rep(j,0,1<<w1) // 保留那些行列
        {
            int line[N],col[N];
            int cnt1=0,cnt2=0;
            rep(k,0,h1-1)
                if(i&(1<<k))
                    line[++cnt1]=k+1;
            rep(k,0,w1-1)
                if(j&(1<<k))
                    col[++cnt2]=k+1;
            if(cnt1!=h2||cnt2!=w2) continue;
            bool f=1;
            rep(o,1,h2) rep(p,1,w2)
                if(a[line[o]][col[p]]!=b[o][p]) f=0;
            if(f)
            {
                cout<<"Yes";
                return 0;
            }
        }
    cout<<"No";
}

// hope to debug successfully