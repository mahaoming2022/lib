#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
    cin>>n;
    vector<bool> vis(n+1);
    vector<int> ps;
    for(int i=2;i<=n;++i)
    {
        if(!vis[i]) ps.push_back(i);
        for(int j=0;j<ps.size();j++)
        {
            if(ps[j]*i>n) break;
            vis[ps[j]*i]=1;
            if(i%ps[j]==0) break;
        }
    }
    for(auto i:ps) cout<<i<<' ';
}