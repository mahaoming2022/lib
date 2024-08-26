#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)

using namespace std;

typedef long long ll;
typedef double db;

const int N=2e5+23;
int n;
ll add[N],tag;
vector<int> upt;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n;
    rep(i,1,n) cin>>add[i],upt.push_back(i);
    int Q;cin>>Q;
    tag=0;
    while(Q--)
    {
        int o;cin>>o;
        if(o==1)
        {
            int x;cin>>x;
            tag=x;
            for(auto i:upt) add[i]=0;
            upt.clear();
        }
        if(o==2)
        {
            int i,x;cin>>i>>x;
            add[i]+=x;
            upt.push_back(i);
        }
        if(o==3)
        {
            int i;cin>>i;
            cout<<add[i]+tag<<endl;
        }
    }
}