#include <bits/stdc++.h>

using namespace std;

const int N=2e5+24;

struct ply{
    int id,sr,w;
    bool operator<(const ply& A)
    {
        if(sr==A.sr)
            return id<A.id;
        return sr>A.sr;
    }
}pyer[N];

int n,R,Q;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    cin>>n>>R>>Q;
    for(int i=1;i<=2*n;++i){
        cin>>pyer[i].sr;
        pyer[i].id=i;
    }
    for(int i=1;i<=2*n;++i)
        cin>>pyer[i].w;
    while(R--)
    {
        sort(pyer+1,pyer+1+2*n);
        // for(int i=1;i<=2*n;++i)
        //     cout<<pyer[i].id<<' '<<pyer[i].sr<<endl;
        for(int i=1;i<2*n;i+=2)
            if(pyer[i].w>pyer[i+1].w)
                pyer[i].sr++;
            else
                pyer[i+1].sr++;
        // cout<<endl;
    }
    sort(pyer+1,pyer+1+2*n);
    cout<<pyer[Q].id;
}
