#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define pii pair<int,int>

using namespace std;

const int N=15024;
const int M=40024;

int m,n;
int cnt[N],magic[M];
int ans[M][6];

bool judge(int a,int b,int c,int d)
{
    return ((b-a)==2*(d-c))&&(3*(b-a)<c-b);
}

int main()
{
    cin>>n>>m;
    rep(i,1,m)
    {
        cin>>magic[i];
        cnt[magic[i]]++;
    }
    rep(a,1,n)
        rep(b,a+1,n)
            rep(c,b+1,n)
                rep(d,c+1,n)
                    if(judge(a,b,c,d)&&cnt[a]&&cnt[b]&&cnt[c]&&cnt[d])
                    {
                        ans[a][1]+=cnt[b]*cnt[c]*cnt[d];
                        ans[b][2]+=cnt[a]*cnt[c]*cnt[d];
                        ans[c][3]+=cnt[a]*cnt[b]*cnt[d];
                        ans[d][4]+=cnt[a]*cnt[b]*cnt[c];
                    }
    rep(i,1,m){
        rep(j,1,4)
            cout<<ans[magic[i]][j]<<' ';
        cout<<endl;
    }
}
