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

// 1 | (A) or 0 & (B) has not to judge

inline bool dfs1(int u,bool f)
{
    bool lv,rv,ans=val[u];
    if(lc[u]) 
        lv=dfs1(lc[u],f^notf[lc[u]]);
    if(rc[u]) 
        rv=dfs1(rc[u],f^notf[rc[u]]);
    if(ans==-1){
        if(!lv)
            tag[rc[u]]=1;
        if(!rv)
            tag[lc[u]]=1;
        ans=lv&rv;
    }
    if(ans==-2){
        ans=lv|rv;
        if(lv)
            tag[rc[u]]=1;
        if(!rv)
            tag[lc[u]]=1;
    }
    return ans;
}

inline void dfs2(int u,bool f)
{
    if(f) tag[lc[u]]=tag[rc[u]]=1;
    if(lc[u])
        dfs2(lc[u],tag[lc[u]]);
    if(rc[u]) 
        dfs2(rc[u],tag[rc[u]]);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
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
                x=x*10+(str[i]-'0');
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
            notf[sta.top()]=1,i++;
    }
    bool ans=dfs1(cnt,notf[cnt]);
    cout<<ans;return 0;
    cin>>Q;
    while(Q--)
    {
        int tmp;
        cin>>tmp;
        cout<<(tag[ndn[tmp]]?ans:!ans)<<endl;
    }
}