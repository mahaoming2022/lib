// 一定一定记得开long long 

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll k,N;
bool c[2024];int len;
// ll ans_list[2024];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    cin>>k>>N;
    int i=N;
        len=0;
        int tmp=i;
        while(tmp)
            c[++len]=tmp&1,tmp>>=1;
        ll kn=0;
        for(ll j=1,pk=1;j<=len;++j,pk*=k)
            kn+=c[j]*pk;
    //     ans_list[i]=kn;
    // cout<<ans_list[N];
    cout<<kn;
}
