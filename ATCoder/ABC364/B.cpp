// #define EXT
#include <bits/stdc++.h>
#ifdef EXT
    #include <bits/extc++.h>
#endif

#define i64 long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define fdn(i,r,l) for(int i=(r);i>=(l);i--)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef double db;
typedef __int128 i128;

const int INF=1<<29;
const ll INFL=1ll<59;

const int N=54;

int h,w,sx,sy;
bool ise[N][N];
string o;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("in.out","w",stdout);
#endif
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>h>>w>>sx>>sy;
    rep(i,1,h) rep(j,1,w)
    {
        char c;cin>>c;
        if(c=='.') ise[i][j]=1;
        if(c=='#') ise[i][j]=0;
    }
    cin>>o;
    for(auto i:o)
    {
        if(i=='L'&&sy>=2&&ise[sx][sy-1]) sy--;
        if(i=='R'&&sy<=w-1&&ise[sx][sy+1]) sy++;
        if(i=='U'&&sx>=2&&ise[sx-1][sy]) sx--;
        if(i=='D'&&sx<=h-1&&ise[sx+1][sy]) sx++;
    }
    cout<<sx<<' '<<sy;
}