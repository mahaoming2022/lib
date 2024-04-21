#include <bits/stdc++.h>
// #define int long long 
#define rep(i,l,r) for(int i=(l);i<=(r);i++)

using namespace std;
typedef long long ll;
typedef __int128 i128;

const int N=1e6+23;

int n;
ll p;
i128 a[N],t[N],s[N],d[N];

inline i128 i_abs(i128 a)
{return a>0?a:-a;}

inline i128 read()
{
    i128 x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
        x=x*10+ch-'0',ch=getchar();
    return x*f;
}

inline void write(i128 x) {
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9) 
        write(x/10);
    putchar(x%10+'0');
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n>>p;
    rep(i,1,n)
        a[i]=read();
    d[1]=t[1]=a[1];
    rep(i,2,n)
        d[i]=max(d[i-1]+a[i],a[i]),t[i]=max(t[i-1],d[i]);
    s[1]=t[1];
    i128 ans=s[1];
    rep(i,2,n){
        if(i==2)
            s[i]=s[i-1]+t[i-1];
        else
            s[i]=max(s[i-1],s[i-1]+t[i-1]);
        ans=max(ans,s[i]);
    }
    bool fg=ans<0?1:0;
    ans=i_abs(ans)%p;
    write(fg?-ans:ans);
}