#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)

using namespace std;

typedef long long ll;
typedef double db;

const int N=2e5+23;
int n;string str;
pair<int,bool> a[N];

bool cmp(pair<int,bool> A,pair<int,bool> B)
{
    return A.first<B.first||(A.first==B.first&&A.second>B.second);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n>>str;
    str=' '+str;
    int ad=0;
    for(int i=1;i<=n;++i){
        a[i].second=str[i]-'0';
        if(a[i].second) ad++;}
    rep(i,1,n) cin>>a[i].first;
    if(ad==0) {cout<<n;return 0;}
    sort(a+1,a+1+n,cmp);
    int ch=0,ans=0;
    rep(i,1,n)
    {
        ans=max(ans,ch+ad);
        if(a[i].second==0) ch++;
        else ad--;
    }
    cout<<ans;
}

// debug
// 有两个容易错的点
// 第一个，第 36,37,38 的顺序
// 第二个，注意 31 行的特判。