#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)

using namespace std;

const int N=114;
const int M=1e4+24;

int n,m,f=0;
int a[N],b[N];
bool vis[N][M];

bool dfs(int i,int s)
{
    if(i==0&&s==m)
    {
        cout<<"Yes"<<endl;
        return 1;
    }
    else if(i==0) return 0;
    if(s>m||vis[i][s]) return 0;
    vis[i][s]=1;
    rep(k,0,1)
        if(dfs(i-1,s+(k?b[i]:a[i]))){
            cout<<(k?'T':'H');
            return 1;
        }
    return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n>>m;
    rep(i,1,n) cin>>a[i]>>b[i];
    if(!dfs(n,0)) cout<<"No";
}

// dbg: 正反别反！