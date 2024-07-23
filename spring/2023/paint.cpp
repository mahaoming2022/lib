#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;++i)

using namespace std;

const int N=1e5+23;

int T,n,m,q;

pair<int,int> line[N],col[N];

int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>q;
        rep(i,1,n) line[i].first=0,line[i].second=0;
        rep(i,1,m) col[i].first=0,col[i].second=0;
        rep(i,1,q)
        {
            int o,x,c;
            cin>>o>>x>>c;
            if(o==0) line[x].first=c,line[x].second=i;
            if(o==1) col[x].first=c,col[x].second=i;
        }
        rep(i,1,n){
            rep(j,1,m)
                if(line[i].second>col[j].second)
                    cout<<line[i].first<<' ';
                else cout<<col[j].first<<' ';
            cout<<endl;
        }
    }
}