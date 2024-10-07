#include <bits/stdc++.h>

#define i64 long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define fdn(i,r,l) for(int i=(r);i>=(l);i--)
#define pii pair<int,int>
using namespace std;

typedef long long ll;
typedef double db;
typedef __int128 i128;

int m;
vector<int> a;

int qp(int x,int y)
{
    if(y==0) return 1;
    int ans=1;
    while(y--) ans*=x;
    return ans;
}

int log3(int x)
{
    int cnt=0;
    for(int i=1;;i*=3)
    {
        if(i*3>x) return cnt;
        cnt++;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>m;
    while(m>0)
    {
        int x=log3(m);
        if(m<3) x=0;
        m=m-qp(3,x);
        a.push_back(x);
    }
    cout<<a.size()<<endl;
    for(auto i:a)
        cout<<i<<' ';
}