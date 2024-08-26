#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define pii pair<int,int>

using namespace std;
typedef long long ll;

const int N=17;

int n,m,tot=0;
string s[N],str;
bool vis[N];
set<string> t;

void dfs(int i,int ad)
{
    if(str.size()>16) return ;
    if(i==n+1)
    {
        if(t.find(str)==t.end()&&str.size()>=3)
        {
            cout<<str;
            exit(0);
        }
        return ;
    }
    string tmp=str;
    rep(j,1,n)
        if(!vis[j]){
            // 加几个下划线是关键
            string str_114514;
            rep(k,1,16)
            {
                if(ad+tot+k+n-i-1>16) break;
                str_114514+='_';
                vis[j]=1;
                str=str+str_114514+s[j];
                dfs(i+1,ad+k);
                str=tmp;
                vis[j]=0;
            }
        }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n>>m;
    rep(i,1,n) cin>>s[i],tot+=s[i].size();
    rep(i,1,m)
    {
        string tt;
        cin>>tt;
        t.insert(tt);
    }
    rep(i,1,n)
    {
        memset(vis,0,sizeof(vis));
        vis[i]=1;
        str=s[i];
        dfs(2,0);
        vis[i]=0;
    }
    cout<<-1;
}