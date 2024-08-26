#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)

using namespace std;
typedef long long ll;
typedef long double db;

const int N=2e5+23;
int n;
int o[N],e[N];
int cnt1=0,cnt2=0;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n;
    rep(i,1,n)
    {
        int a;
        cin>>a;
        if(a&1) o[++cnt1]=a;
        else e[++cnt2]=a;
    }
    sort(o+1,o+1+cnt1);
    sort(e+1,e+1+cnt2);
    if(cnt1<2&&cnt2<2)
    {
        cout<<-1;
        return 0;
    }
    if(cnt1<2&&cnt2>=2)
    {
        cout<<e[cnt2]+e[cnt2-1];
    }
    if(cnt1>=2&&cnt2<2)
    {
        cout<<o[cnt1]+o[cnt1-1];
    }
    if(cnt1>=2&&cnt2>=2)
    {
        cout<<max(e[cnt2]+e[cnt2-1],o[cnt1]+o[cnt1-1]);
    }
}