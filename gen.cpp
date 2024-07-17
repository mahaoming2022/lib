#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);++i)

using namespace std;
typedef long long ll;
typedef double db;

inline char rn()
{
    int r=rand()%4;
    if(r==0) return '(';
    if(r==1) return ')';
    if(r==2) return '[';
    if(r==3) return ']';
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","w",stdout);
    // freopen("out.out","w",stdout);
#endif
    int n=400;
    cout<<n<<endl;
    srand(time(0));
    for(int i=1;i<=n;++i)
        cout<<rn();
}