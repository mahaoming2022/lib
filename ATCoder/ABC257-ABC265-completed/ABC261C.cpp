#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)

using namespace std;

typedef long long ll;
typedef double db;

const int N=2e5+23;

int n;
map<string,int> cnt;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n;
    rep(i,1,n)
    {
        string str;
        cin>>str;
        cout<<str;
        if(cnt[str]) cout<<'('<<cnt[str]<<')';
        cout<<endl;
        cnt[str]++;
    }
}