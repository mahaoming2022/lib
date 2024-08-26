#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)

using namespace std;
typedef long long ll;
typedef double db;

const int N=1024;

int n;
int a[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif  
    cin>>n;
    rep(i,1,n) cin>>a[i];
    int G=a[1];
    rep(i,2,n) G=__gcd(G,a[i]);
    int ans=0;
    rep(i,1,n)
    {
        int x=a[i]/G;
        while(x%2==0) x>>=1,ans++;
        while(x%3==0) x/=3,ans++;
        if(x!=1){cout<<-1;return 0;} 
    }
    cout<<ans;
}