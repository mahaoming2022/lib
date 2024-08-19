#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)

using namespace std;
typedef long long ll;
typedef double db;

string s;
int pos;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>s;
    pos=s.size()-1;
    while(s[pos]=='0') pos--;
    if(s[pos]=='.') pos--;
    for(int i=0;i<=pos;i++) cout<<s[i];
}