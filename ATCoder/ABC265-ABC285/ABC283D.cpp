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

const int N=250;

int len,f[N];
string s;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>s;len=s.size();s=' '+s;
    int x=1;
    rep(i,1,len)
    {
        if(s[i]=='(') x++;
        if(s[i]>='a'&&s[i]<='z')
        {
            if(f[s[i]]==0)
                f[s[i]]=x;
            else 
            {
                cout<<"No";
                return 0;
            }
        }
        if(s[i]==')')
        {
            rep(j,'a','z')
                if(f[j]==x)
                    f[j]=0;
            x--;
        }
    }
    cout<<"Yes";
}

// hope to debug successfully