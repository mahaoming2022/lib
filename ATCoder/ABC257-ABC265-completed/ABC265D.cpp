#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)

using namespace std;
typedef long long ll;

const int N=2e5+23;

int n;
set<ll> s({0});

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    ll p,q,r;
    cin>>n>>p>>q>>r;
    ll sum=0;
    rep(i,1,n)
    {
        ll ai;
        cin>>ai;
        sum+=ai;
        s.insert(sum);
    }
    for(auto i:s)
    {
        if(s.find(i+p)!=s.end()&&s.find(i+p+q)!=s.end()&&s.find(i+p+q+r)!=s.end())
        {
            cout<<"Yes";return 0;
        }
    }
    cout<<"No";
}

// 第十行要初始化，因为如果从第一个开始加呢？