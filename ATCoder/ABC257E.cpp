#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)

using namespace std;

typedef long long ll;
typedef double db;

int n;
int s[11];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n;
    int mi=1919810,ii;
    rep(i,1,9){cin>>s[i];if(s[i]<mi) ii=i,mi=s[i];}
    int len=n/mi;n%=mi;
    for(int i=9;i>ii;i--) while(len&&n>=s[i]-s[ii]) n-=s[i]-s[ii],len--,cout<<i;
    while(len--) cout<<ii;
} 