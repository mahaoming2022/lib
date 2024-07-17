#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);++i)

using namespace std;
typedef long long ll;
typedef double db;

const int N=10024;

int n,m,H=0,W=0;
int a[N][N];
char s[N][N];
const char t[10][10]=
{
    "..+---+",
    "./   /|",
    "+---+ |",
    "|   | +",
    "|   |/.",
    "+---+.."
};

inline void draw(int x,int y)
{
    for(int i=0;i<6;i++)
        for(int j=0;j<7;j++)
            if(t[5-i][j]!='.')
                s[x+i][y+j]=t[5-i][j];
    H=max(H,x+6),W=max(W,y+7);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n>>m;
    rep(i,0,n-1) rep(j,0,m-1) cin>>a[i][j];
    memset(s,46,sizeof(s));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            for(int k=0;k<a[i][j];k++)
            {
                int x=3*k+2*(n-1-i);
                int y=4*j+2*(n-1-i);
                draw(x,y);
            }
    for(int i=H-1;i>=0;i--){for(int j=0;j<W;j++)cout<<s[i][j];cout<<endl;}
}