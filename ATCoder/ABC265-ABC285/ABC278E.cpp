#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)

using namespace std;
typedef long long ll;
typedef double db;

const int N=314;
int a[N][N],f[N][N];
int cnt[N],cnt1[N];
int ans=0,ans1=0;
int n,m,k,h,w;

void add(int x)
{
    if(!cnt[x]) ans++;
    cnt[x]++;
}

void del(int x)
{
    cnt[x]--;
    if(!cnt[x]) ans--;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n>>m>>k>>h>>w;
    rep(i,1,n) rep(j,1,m)
    {
        cin>>a[i][j];
        if(!cnt[a[i][j]]) ans++,ans1++;
        cnt[a[i][j]]++,cnt1[a[i][j]]++;
    }
    rep(i,1,n-h+1)
    {
        // 还原
        ans=ans1;
        rep(k0,1,k) cnt[k0]=cnt1[k0];
        rep(j,i,i+h-1)
            rep(k,1,w)
                del(a[j][k]);
        f[i][1]=ans;
        rep(j,1,m-(w-1))
        {
            rep(k,i,h+i-1)
                add(a[k][j]),del(a[k][j+w]);
            // 滑动
            f[i][j+1]=ans;
        }
    }
    rep(i,1,n-h+1)
    {
        rep(j,1,m-w+1) cout<<f[i][j]<<' ';
        cout<<endl;
    }
}