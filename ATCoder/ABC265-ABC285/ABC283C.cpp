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

string s;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>s;
    int ans=0,i=0;
    while(i<s.size())
    {
        if(s[i]=='0'&&i==s.size()-1) ans++,i++;
        else if(s[i]=='0'&&s[i+1]=='0')
            ans++,i+=2;
        else ans++,i++; 
    }
    cout<<ans;
}

// hope to debug successfully