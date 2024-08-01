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

const int N=114;
const int M=10024;

int n,x,y;
vector<pair<int,int> > s;
int a[N],b[N];
int mem[N][M][N];

int cmp1(pair<int,int> A,pair<int,int> B)
{
    return A.first<B.first;
}

int cmp2(pair<int,int> A,pair<int,int> B)
{
    return A.second+A.first<B.first+B.second;
}

inline int dp(int d,int xx,int yy,int cnt)
{
    if(d==n+1) return cnt;
    int& ans=mem[d][xx][cnt];
    if(ans!=-1) return ans;
    int ans0=0,ans1=0;
    if(xx>=a[d]&&yy>=b[d]) ans0=dp(d+1,xx-a[d],yy-b[d],cnt+1);
    else ans0=cnt+1;
    ans1=dp(d+1,xx,yy,cnt);
    return ans=max(ans0,ans1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("in.out","w",stdout);
#endif
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    memset(mem,-1,sizeof(mem));
    cin>>n>>x>>y;
    rep(i,1,n){int ai,bi;cin>>ai>>bi;s.push_back({ai,bi});}
    int ans1,ans2;
    // sort(s.begin(),s.end(),cmp1);
    // for(int i=0;i<s.size();++i) a[i+1]=s[i].first,b[i+1]=s[i].second;
    // ans1=dp(1,x,y,0);
    sort(s.begin(),s.end(),cmp2);
    for(int i=0;i<s.size();++i) a[i+1]=s[i].first,b[i+1]=s[i].second;
    ans2=dp(1,x,y,0);
    cout<<ans2;
}