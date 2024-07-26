#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)

using namespace std;

typedef long long ll;
typedef double db;

int n,q;
string s,t;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n>>q>>s;
    s=' '+s;
    int pos=0;
    rep(i,1,q)
    {
        int o,x;
        cin>>o>>x;
        if(o==1) pos+=x;
        else pos%=n,cout<<((x-pos>=1)?s[x-pos]:s[n+x-pos])<<endl;
    }
}

// xxx|xxllll
// llxxx|xxll 