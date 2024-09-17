#include <bits/stdc++.h>

#define i64 long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define fdn(i,r,l) for(int i=(r);i>=(l);i--)
#define pii pair<int,int>
using namespace std;

typedef long long ll;
typedef double db;
typedef __int128 i128;

ll f(string s)
{
    ll cnt=0,ans=0;
    for(auto i:s)
    {
        if(i=='X') cnt++;
        else ans+=cnt*(i-'0');
    }
    return ans;
}

bool cmp(string s1,string s2)
{
    return f(s1+s2)>f(s2+s1);
}

int main()
{
#ifndef ONLINE_JUDGE 
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n;
    cin>>n;
    vector<string> s(n);
    rep(i,0,n-1) cin>>s[i];
    sort(s.begin(),s.end(),cmp);
    string o="";
    for(auto& i:s) o+=i;
    cout<<f(o)<<endl;
}