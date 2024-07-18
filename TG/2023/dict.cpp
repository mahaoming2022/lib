#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)

using namespace std;

const int N=3356;

int n,m;
int m1[N],m2[N]; // m1 max m2 min
string s;

int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    rep(i,1,n)
    {
        cin>>s;s=' '+s;
        int o1='a'-1,o2='z'+1;
        rep(j,1,m)
            o1=max(o1,(int)s[j]),o2=min(o2,(int)s[j]);
        m1[i]=o1,m2[i]=o2;
    }
    rep(i,1,n)
    {
        bool fg=1;
        rep(j,1,n) if(j!=i)
        {
            if(m2[i]>=m1[j])
            {fg=0;break;}
        }
        cout<<(fg?1:0);
    }
}