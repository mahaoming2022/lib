// #define EXT
#include <bits/stdc++.h>
#ifdef EXT
    #include <bits/extc++.h>
#endif

//define
#define i64 long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define fdn(i,r,l) for(int i=(r);i>=(l);i--)
#define pii pair<int,int>

using namespace std;

// type define
typedef long long ll;
typedef double db;
typedef __int128 i128;
#ifdef EXT
    typedef unsigned int ui;
    typedef unsigned long long ull;
    typedef long double ldb;
#endif

// const integer

const int INF=1<<29;
const ll INFL=1ll<59;

// const array
const int Dx4[]={0,0,1,-1};
const int Dy4[]={1,-1,0,0};
const int Dx8[]={0,0,1,1,1,-1,-1,-1};
const int Dy8[]={1,-1,0,-1,1,0,-1,1};
const ll M10[]={1,10,100,1000,10000,100000,1000000,(ll)1e7,(ll)1e8,(ll)1e9,(ll)1e10,(ll)1e11,(ll)1e12,(ll)1e13,(ll)1e14,(ll)1e15,(ll)1e16,(ll)1e17,(ll)1e18};

//fast IO
inline int readi(){int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0' && ch<='9')x=x*10+ch-'0',ch=getchar();return x*f;}

template<typename T> inline 
void read(T& x){x=0;T f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0' && ch<='9')x=x*10+ch-'0',ch=getchar();x*=f;}

template<typename T> inline
void write(T x){if(x<0){putchar('-');x=-x;}if(x>9) write(x/10);putchar(x%10+'0');}

const int N=2e5+24;

int n,k;
int a[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>
    rep(i,1,n-1){
        cin>>a[i];
    }
}