#include <bits/stdc++.h>

using namespace std;

int n,a[520][520];

int main()
{
    //freopen("in.in","r",stdin);
    cin>>n;
    for(int i=1;i<n;++i)
        for(int j=i+1;j<=n;++j)
        {
            cin>>a[i][j];
            a[j][i]=a[i][j];
        }
    int ans=0;
    for(int i=1;i<=n;++i){
        sort(a[i]+1,a[i]+n+1);
        ans=max(ans,a[i][n-1]);
    }
    cout<<1<<endl<<ans;
}
