#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)

using namespace std;
typedef long long ll;
typedef double db;

const int N=5e5+23;
int latest,pos;
int v[N],fa[N];
unordered_map<int,int> edi;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif  
    int Q;
    cin>>Q;
    while(Q--)
    {
        string o;
        cin>>o;
        if(o=="ADD")
        {
            int x;
            cin>>x;
            v[++pos]=x;
            fa[pos]=latest;
            latest=pos;
        }
        if(o=="DELETE")
            latest=fa[latest];
        if(o=="SAVE"){int x;cin>>x;edi[x]=latest;}
        if(o=="LOAD"){int x;cin>>x;latest=edi[x];}
        if(!v[latest]) cout<<-1<<' ';
        else cout<<v[latest]<<' ';
    }
}