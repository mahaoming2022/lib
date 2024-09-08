// Written by da_ke
// Website: https://mahaoming2022.github.io

#include <bits/stdc++.h>

#define i64 long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define fdn(i,r,l) for(int i=(r);i>=(l);i--)
#define pii pair<int,int>
using namespace std;

typedef long long ll;
typedef double db;
typedef __int128 i128;

const int INF=1<<29;
const ll INFL=1ll<<59;

//fast IO
inline int readi(){int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0' && ch<='9')x=x*10+ch-'0',ch=getchar();return x*f;}

inline ll readl(){ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0' && ch<='9')x=x*10+ch-'0',ch=getchar();return x*f;}

template<typename T> inline 
void read(T& x){x=0;T f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0' && ch<='9')x=x*10+ch-'0',ch=getchar();x*=f;}

template<typename T> inline
void write(T x){if(x<0){putchar('-');x=-x;}if(x>9) write(x/10);putchar(x%10+'0');}

const int N=3e5+1;

int n,Q;
vector<int> fa;
// int fa[N<<1],r[N<<1],b[N<<1],ans[N<<1];

int find(int x)
{
    if(fa[x]==x) return fa[x];
    return fa[x]=find(fa[x]);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>n>>Q;
    fa.resize(n+Q+1);
    vector<int> r(n+Q+1),ans(n+Q+1),b(n+Q+1); // r 和 ans 相互映射
    rep(i,1,n) fa[i]=r[i]=ans[i]=b[i]=i; // init
    int id=n,nb=n;
    while(Q--)
    {
        int o,x,y;
        cin>>o>>x;
        if(o==1)
        {
            cin>>y;
            fa[r[y]]=r[x];
            id++;
            ans[id]=y,fa[id]=id,r[y]=id;
        }
        if(o==2)
            b[++nb]=r[x];
        if(o==3)
            cout<<ans[find(b[x])]<<endl;
    }
}

// hope to debug successfully