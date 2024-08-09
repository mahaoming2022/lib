#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)

using namespace std;

typedef long long ll;
typedef double db;

string s,t;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>t;
    t=' '+t;
    s="atcoder";s=' '+s;
    int ans=0;
    rep(i,1,7)
        if(t[i]!=s[i])
            rep(j,i,7)
                if(t[j]==s[i])
                {
                    ans+=j-i;
                    for(int k=j;k>i;k--)
                        swap(t[k],t[k-1]);
                }
    cout<<ans;
}