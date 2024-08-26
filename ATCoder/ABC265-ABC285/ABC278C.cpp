#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)

using namespace std;
typedef long long ll;
typedef double db;

const int N=2e5+23;

map<int,set<int> > linker;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif  
    int n,Q;
    cin>>n>>Q;
    while(Q--)
    {
        int o,a,b;
        cin>>o>>a>>b;
        if(o==1)
            linker[a].insert(b);
        if(o==2)
            linker[a].erase(b);
        if(o==3)
        {
            if(linker[a].find(b)!=linker[a].end()&&
                linker[b].find(a)!=linker[b].end())
                    cout<<"Yes";
            else cout<<"No";cout<<endl;
        }
    }
}