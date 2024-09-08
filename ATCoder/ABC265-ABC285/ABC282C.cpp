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

int len;
string s;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>len>>s;
    int cd=0;
    rep(i,0,len-1)
    {
        if(s[i]=='"'&&(!cd)) cd=1;
        else if(s[i]=='"'&&cd) cd=0;
        if(s[i]==','&&(!cd)) s[i]='.';
    }
    cout<<s;
}

// hope to debug successfully