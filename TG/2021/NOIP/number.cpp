#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;++i)

using namespace std;

const int M=1e7+23;

int T;
int cnt=0,c[M];
bitset<M> f;

bool has7(int u)
{
    while(u)
    {if(u%10==7) return 1;u/=10;}
    return 0;
}

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>T;
    for(int i=1;i<=M;++i)
        if(!f[i]&&has7(i)){
            for(int j=i;j<=M;j+=i)
                f[j]=1;
            f[i]=1;
        }
    for(int i=1;i<=M;++i)
        if(!f[i]) c[++cnt]=i;
    while(T--)
    {
        int x;cin>>x;
        if(f[x]) cout<<-1<<endl;
        else
        {
            int pos=lower_bound(c+1,c+1+cnt,x)-c;
            cout<<c[pos+1]<<endl;
        }
    }
}