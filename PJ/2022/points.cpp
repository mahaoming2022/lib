#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
const int N=524;

int n,k;
pii a[N];
int mem[N][N];
bool cmp(const pii& A,const pii& B){if(A.first==B.first) return A.second<B.second;else return A.first<B.first;}

inline int dp(int i,int p)
{
    int& ans=mem[i][p];
    if(ans!=-1)
        return ans;
    if(p==0)
        ans=1;
    rep(j,i+1,n)
    {
        if(a[i].second>a[j].second)
            continue;
        int dis=abs(a[i].first-a[j].first)+abs(a[i].second-a[j].second);
        if(p-dis+1<0)
            continue;
        ans=max(ans,dp(j,p-dis+1)+dis);
    }
    ans=max(ans,p+1);
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n>>k;
    rep(i,1,n)
        cin>>a[i].first>>a[i].second;
    sort(a+1,a+1+n,cmp);
    memset(mem,-1,sizeof(mem));
    int ans=0;
    rep(i,1,n)
        rep(j,0,k)
            ans=max(ans,dp(i,j));
    cout<<ans;
}