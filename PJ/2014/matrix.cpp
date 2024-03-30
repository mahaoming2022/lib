#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n,I,J;

int calc(int n,int i,int j)
{
    if(i==1)
        return j;
    if(j==n)
        return i+n-1;
    if(i==n)
        return 3*n-j-1;
    if(j==1)
        return 4*n-2-i;
    return 4*(n-1)+calc(n-2,i-1,j-1);   
}

int main()
{
// #ifndef ONLINE_JUDGE
    freopen("matrix.in","r",stdin);
// #endif
    cin>>n>>I>>J;
    cout<<calc(n,I,J);
}
