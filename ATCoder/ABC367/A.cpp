#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)

using namespace std;
typedef long long ll;
typedef double db;

int a,b,c;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>a>>b>>c;
    for(int i=b;;)
    {
        if(i==c) break; 
        if(i==a)
        {cout<<"No";return 0;}
        i++;
        if(i==24) i=0;
    }
    cout<<"Yes";
}