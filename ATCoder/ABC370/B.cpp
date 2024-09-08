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
int a[114][114];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>n;
    rep(i,1,n) rep(j,1,i) cin>>a[i][j];
    int i=1;
    rep(j,1,n)
    {
        if(i>=j) i=a[i][j];
        else if(i<j) i=a[j][i];
    }
    cout<<i;
}

// hope to debug successfully