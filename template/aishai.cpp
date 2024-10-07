#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
    cin>>n;
    vector<bool> vis(n+1,0);
    for(int i=2;i*i<=n;++i)
        if(!vis[i])
        {
            for(int j=i*i;j<=n;j+=i)
                vis[j]=1;
        }
    for(int i=2;i<=n;i++)
        if(!vis[i]) cout<<i<<' ';
}