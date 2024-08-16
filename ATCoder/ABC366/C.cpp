#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)

using namespace std;
typedef long long ll;
typedef double db;

int Q,cnt=0;
map<int,int> s;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>Q;
    while(Q--)
    {
        int o,x;
        cin>>o;
        if(o==1)
        {
            cin>>x;
            if(s[x]==0) cnt++;
            s[x]++;
        }
        if(o==2)
        {
            cin>>x;
            s[x]--;
            if(s[x]==0) cnt--;
        }
        if(o==3)
            cout<<cnt<<endl;
    }
}