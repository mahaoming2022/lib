#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define pii pair<int,int>

using namespace std;

int ax,ay,bx,by,cx,cy,dx,dy;

int times(pii A,pii B)
{
    return A.first*B.first+A.second*B.second;
}

pii iv(pii A){return {-A.first,-A.second};}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>ax>>ay>>bx>>by>>cx>>cy>>dx>>dy;
    // AB
    int f=0;
    pii vab={bx-ax,by-ay};
    pii vac={cx-ax,cy-ay};
    pii vad={dx-ax,dy-ay};
    pii vbc={cx-bx,cy-by};
    pii vbd={dx-bx,dy-by};
    pii vcd={dx-cx,dy-cy};
    if(times(vab,vac)*times(vab,vad)<=0) f=1;
    if(times(iv(vab),vbc)*times(iv(vab),vbd)<=0) f=1;
    if(times(iv(vbc),vcd)*times(iv(vbc),iv(vac))<=0) f=1;
    if(times(iv(vcd),iv(vad))*times(iv(vcd),iv(vbd))<=0) f=1;
    if(!f) cout<<"Yes";
    else cout<<"No";
}