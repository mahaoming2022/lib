#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;

const int N=1e5+23;

int n,Q;
string str;
bool a[N],notf[N],tag[N];
int val[N],lc[N],rc[N]; //expr tree
int ndn[N];
stack<int> sta;

inline int dfs1(int u)
{
    bool f=notf[u];
    if(!lc[u]&&!rc[u])
        return (f?(!val[u]):val[u]);
    else
    {
        bool v1=dfs1(lc[u]);
        bool v2=dfs1(rc[u]);
        bool ans;
        if(val[u]==-1) //&
        {
            if(!v1)
                tag[rc[u]]=1;
            if(!v2)
                tag[lc[u]]=1;
            ans=v1&v2;
        }
        if(val[u]==-2) //|
        {
            if(v1)
                tag[rc[u]]=1;
            if(v2)
                tag[lc[u]]=1;
            ans=v1|v2;
        }
        return (f?(!ans):ans);
    }
}

inline void dfs2(int u)
{
    if(!lc[u]&&!rc[u])
        return;
    else
    {
        if(tag[u]) tag[lc[u]]=1;
        if(tag[u]) tag[rc[u]]=1;
        dfs2(lc[u]);
        dfs2(rc[u]);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    //believe2024zk
#endif
    ios::sync_with_stdio(false);
    getline(cin,str);
    int len=str.size();
    cin>>n;
    rep(i,1,n)
        cin>>a[i];
    int cnt=0;  
    for(int i=0;i<len;)
    {
        if(str[i]==' ')
        {
            i++;
            continue;
        }
        if(str[i]=='x')
        {
            int x=0;
            i++;
            while(str[i]!=' ')
            {
                x=x*10+str[i]-'0';
                i++;
            }
            val[++cnt]=a[x];
            ndn[x]=cnt;
            sta.push(cnt);
        }
        if(str[i]=='&')
        {
            int x=sta.top();sta.pop();
            int y=sta.top();sta.pop();
            val[++cnt]=-1;
            lc[cnt]=x;
            rc[cnt]=y;
            sta.push(cnt);
            i++;
        }
        if(str[i]=='|')
        {
            int x=sta.top();sta.pop();
            int y=sta.top();sta.pop();
            val[++cnt]=-2;
            lc[cnt]=x;
            rc[cnt]=y;
            sta.push(cnt);
            i++;
        }
        if(str[i]=='!')
            notf[sta.top()]^=1,i++;
    }
    int ans=dfs1(cnt); 
    dfs2(cnt);
    int Q;
    cin>>Q;
    while(Q--)
    {
        int x;
        cin>>x;
        cout<<(tag[ndn[x]]?ans:!ans)<<endl;
    }
}