#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)

using namespace std;
typedef long long ll;
typedef double db;

const int N=1e3+24;
const int H=1e4+1;

int n,ex,ey;
int f[N][2*H],g[N][2*H],o[N],e[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n>>ex>>ey;
    ex+=H,ey+=H;
    int co=0,ce=0;
    rep(i,1,n)
    {
        int ai;cin>>ai;
        if(i&1) o[++co]=ai; // 横
        else e[++ce]=ai; // 纵
    }
    // dp(i,j)=dp(i-1,j-a[i])|dp(i-1,j+a[i])
    f[0][H]=1;
    rep(i,1,ce)
        rep(j,e[i],2*H)
            f[i][j]=f[i-1][j-e[i]]|f[i-1][j+e[i]];
    g[1][o[1]+H]=1;
    rep(i,2,co)
        rep(j,o[i],2*H)
            g[i][j]=g[i-1][j-o[i]]|g[i-1][j+o[i]];
    if(f[ce][ey]&&g[co][ex]) cout<<"Yes";
    else cout<<"No";
}

// 错误原因：滚动数组瞎滚导致的。