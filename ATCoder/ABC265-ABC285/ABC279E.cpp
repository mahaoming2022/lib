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
const ll INFL=1ll<59;

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

int n,m;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n>>m;
    vector<int> a(m+1),b(n+1),pos(n+1);
    rep(i,1,m) cin>>a[i];
    rep(i,1,n) b[i]=i;
    rep(i,1,m) swap(b[a[i]],b[a[i]+1]); // 操作
    rep(i,1,n) pos[b[i]]=i,b[i]=i; // 还原
    rep(i,1,m)
    {
        if(b[a[i]]==1)
            cout<<pos[b[a[i]+1]]<<endl;
        else if(b[a[i]+1]==1)
            cout<<pos[b[a[i]]]<<endl;
        else cout<<pos[1]<<endl;
        swap(b[a[i]],b[a[i]+1]);
    }
}