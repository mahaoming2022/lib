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
string S,T;
vector<string> c;

void dfs(string s,int cnt)
{
    if(s==T)
    {
        cout<<cnt<<endl;
        for(auto i:c) cout<<i<<endl;
        return ;
    }
    string mx="";
    rep(i,0,len-1)
        if(s[i]!=T[i])
        {
            if(mx=="") mx=s,mx[i]=T[i];
            else 
            {
                string tmp=s;
                tmp[i]=T[i];
                if(tmp<mx) mx=tmp;
            }
        }
    c.push_back(mx);
    dfs(mx,cnt+1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>S>>T;
    len=S.size();
    dfs(S,0);
}

// hope to debug successfully

// bb
// ca
// cb
// ba