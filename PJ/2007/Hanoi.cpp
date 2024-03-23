#include <bits/stdc++.h>

using namespace std;

vector<int> f;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    int n;
    cin>>n;
    f.push_back(0);
    while(n--)
    {
        //f[0]=0;
        //f[n]=2*f[n-1]+2;
        int rm=0;
        for(int i=0;i<f.size();++i)
        {
            f[i]=f[i]*2+rm;
            rm=f[i]/10;
            f[i]%=10;
            // cout<<f[i]<<endl;
        }
        if(rm)
            f.push_back(rm);
        rm=0;
        f[0]+=2;
        rm=f[0]/10;
        f[0]%=10;
        for(int k=1;k<f.size();++k)
        {
            f[k]+=rm;
            rm=f[k]/10;
            f[k]%=10;
        }
        if(rm)
            f.push_back(rm);
        // for(auto i:f)
        //     cout<<i;
        // cout<<endl;
    }
    reverse(f.begin(),f.end());
    for(auto i:f)
        cout<<i;
}
