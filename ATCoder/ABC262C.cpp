#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)

using namespace std;

typedef long long ll;
typedef double db;

const int N=5e5+23;

int n;
int a[N],cnt=0;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n;
    ll ans1=0,ans=0;
    rep(i,1,n)
    {
        int x;
        cin>>x;
        if(x==i) ans1++;
        else if(cnt>=x&&a[x]==i) ans++;
        a[++cnt]=x;
    }
    cout<<ans+(ans1-1)*ans1/2;
}

// debug
// 十年 OI 一场空，不开 long long 见祖宗。