#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);++i)

using namespace std;
typedef long long ll;
typedef double db;

const int N=1e4+23;
const int M=3e4+23;

int n,m1,m2,s[N];
bool vis[M];
int cnt=0,prime[M],f1[M],f2[M];

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n>>m1>>m2;
    rep(i,1,n) cin>>s[i];
    for(int i=2;i*i<=M;++i)
        if(!vis[i]) for(int j=i*i;j<=M;j+=i)
            vis[j]=1;
    for(int i=2;i<M;++i)
        if(!vis[i])
            prime[++cnt]=i;
    for(int i=1;i<=cnt&&prime[i]*prime[i]<=m1;++i)
        while(m1%prime[i]==0) f1[prime[i]]+=m2,m1/=prime[i];
    if(m1!=1) f1[m1]+=m2;
    int ans=1<<29;
    rep(k,1,n)
    {
        memset(f2,0,sizeof(f2));
        for(int i=1;i<=cnt&&prime[i]*prime[i]<=s[k];++i){
            while(s[k]%prime[i]==0) f2[prime[i]]++,s[k]/=prime[i];
        }
        if(s[k]!=1&&s[k]<=M) f2[s[k]]++; // 注意 RE
        bool flag=1;int tans=0;
        for(int i=1;i<=cnt;++i)
        {
            int u1=f1[prime[i]],u2=f2[prime[i]];
            if(u1&&!u2){flag=0;break;}
            else if(u1&&u2)
            {
                if(u2%u1==0) tans=max(tans,u1/u2);
                else tans=max(tans,(int)ceil(1.0*u1/u2));
            }
        }
        if(flag) ans=min(ans,tans);
    }
    cout<<((ans==1<<29)?-1:ans);
}