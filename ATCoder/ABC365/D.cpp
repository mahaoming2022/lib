#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)

using namespace std;

typedef long long ll;
typedef double db;

const int N=2e5+23;

int n;
string s;
int mem[N][5],c[N];

/*
Paper 1
Sissor 2
Rock 3
*/

inline int dp(int d,int lst)
{
    int& ans=mem[d][lst];
    if(ans!=-1) return ans;
    if(d==n+1) return 0;
    int ans1=0,ans2=0;
    if(c[d]==1)
    {
        if(lst!=2) ans1=1+dp(d+1,2);
        if(lst!=1) ans2=dp(d+1,1);
    }
    if(c[d]==2)
    {
        if(lst!=3) ans1=1+dp(d+1,3);
        if(lst!=2) ans2=dp(d+1,2);
    }
    if(c[d]==3)
    {
        if(lst!=1) ans1=1+dp(d+1,1);
        if(lst!=3) ans2=dp(d+1,3);
    }
    return ans=max(ans1,ans2);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n>>s;
    s=' '+s;
    rep(i,1,n)
    {
        if(s[i]=='P') c[i]=1;
        if(s[i]=='S') c[i]=2;
        if(s[i]=='R') c[i]=3;
    }
    memset(mem,-1,sizeof(mem));
    cout<<dp(1,0);
}