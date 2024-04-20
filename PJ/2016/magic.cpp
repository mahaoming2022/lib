#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define pii pair<int,int>

using namespace std;

const int N=15034;
const int M=45024;

int n,m;
int x[M],cnt[N];
int a[N],b[N],c[N],d[N];

int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    cin>>n>>m;
    rep(i,1,m){
        cin>>x[i];
        cnt[x[i]]++;
    }
    for(int t=1;t*9<n;++t)
    {
        int sum=0;
        rep(D,9*t+2,n)
        {
            int A=D-9*t-1;
            int B=A+2*t;
            int C=D-t;
            sum+=cnt[A]*cnt[B];
            c[C]+=cnt[D]*sum;
            d[D]+=cnt[C]*sum;
        }
        sum=0;
        for(int A=n-9*t-1;A>=1;A--)
        {
            int B=A+2*t;
            int C=B+6*t+1;
            int D=A+9*t+1;
            sum+=cnt[C]*cnt[D];
            a[A]+=cnt[B]*sum;
            b[B]+=cnt[A]*sum;
        }
    }
    for(int i=1;i<=m;i++){
		printf("%d %d %d %d\n",a[x[i]],b[x[i]],c[x[i]],d[x[i]]);
	}
}
