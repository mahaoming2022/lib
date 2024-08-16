#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)

using namespace std;
typedef long long ll;
typedef double db;

const int N=114;

int n;
int s[N][N],buf[N][N],sz[N],t[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n;
    int m=0;
    rep(i,1,n)
    {
        string tmp;
        cin>>tmp;
        m=max(m,(int)tmp.size());
        tmp=' '+tmp;
        rep(j,1,tmp.size()-1)
            s[i][j]=tmp[j];
        t[i]=tmp.size()-1;
    }
    rep(j,1,m){
        for(int i=n;i>=1;i--)
            if(j>t[i])
                buf[j][n-i+1]='*';
            else buf[j][n-i+1]=s[i][j];
    }
    rep(i,1,m)
    {
        int j=n;
        while(buf[i][j]=='*') j--;
        sz[i]=j;
    }
    rep(i,1,m){
        rep(j,1,sz[i])
            cout<<(char)buf[i][j];
        cout<<endl;
    }
}