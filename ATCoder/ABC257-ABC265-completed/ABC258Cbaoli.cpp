#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)

using namespace std;

typedef long long ll;
typedef double db;

int n,q;
string s;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n>>q>>s;
    s=' '+s;
    rep(i,1,q)
    {
        int o,x;
        cin>>o>>x;
        if(o==1)
            s=' '+s.substr(n-x+1,x)+s.substr(1,n-x);
        else cout<<s[x]<<endl;
    }
} 

// debug
// 25行一定加 ' ' 