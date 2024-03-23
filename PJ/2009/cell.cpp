#include <bits/stdc++.h>

using namespace std;

const int N=10024;
const int MM=30034;

int n,m1,m2;
int ps=0;
int s[N],prime[MM];
int f1[MM],f2[MM];
bitset<MM> vis;

int main(){
    freopen("in.in","r",stdin);
    cin>>n>>m1>>m2;
    for(int i=1;i<=n;++i)
        cin>>s[i];
    
    // Step 1 : 埃筛
    for(int i=2;i*i<=MM;++i)
        if(!vis[i])
            for(int j=i*i;j<=MM;j+=i)
                vis[j]=1;
    for(int i=2;i<=MM;++i)
        if(!vis[i])
            prime[++ps]=i;

    // Step 2 : 分解质因数m1^(m2)
    for(int i=1;i<=ps&&prime[i]*prime[i]<=m1;++i)
        while(m1%prime[i]==0)
            f1[prime[i]]+=m2,m1/=prime[i];
    if(m1!=1)
        f1[m1]+=m2;

    // Step 3 : 枚举Si
    int ans=1<<30;
    for(int i=1;i<=n;++i){
        memset(f2,0,sizeof(f2));
        bool ok=1;
        int tans=0;

        // Step 4 : 分解Si
        for(int it=1;it<=ps&&prime[it]*prime[it]<=s[i];++it)
            while(s[i]%prime[it]==0)
                f2[prime[it]]++,s[i]/=prime[it];
        if(s[i]!=1&&s[i]<=MM)
            f2[s[i]]++;

        // Step 5 : 处理指数
        for(int j=1;j<=ps;++j)
        {
            int o1=f1[prime[j]];
            int o2=f2[prime[j]];
            if(o1!=0&&o2==0)
                ok=0;
            if(o1!=0&&o2!=0)
            {
                if(o1%o2==0)
                    tans=max(tans,o1/o2);
                else 
                    tans=max(tans,o1/o2+1);
            }
        }
        if(ok)
            ans=min(ans,tans);
    }
    cout<<((ans==1<<30)?-1:ans);
}
