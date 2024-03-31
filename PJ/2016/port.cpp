#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e5+24;

struct node{
    int t,x;
};

int n;
queue<node> q;
int x[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        int ti,ki;
        cin>>ti>>ki;
        while(ki--){
            int na;
            cin>>na;
            q.push({ti,na});
            if(!x[na])
                ans++;
            x[na]++;
        }
        while(ti-q.front().t>=86400)
        {
            x[q.front().x]--;
            if(!x[q.front().x])
                ans--;
            q.pop();
        }
        cout<<ans<<endl;
    }
}
