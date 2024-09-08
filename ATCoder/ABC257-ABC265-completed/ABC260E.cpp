   // Written by da_ke
// Website: https://mahaoming2022.github.io

#include <bits/stdc++.h>

#define i64 long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define fdn(i,r,l) for(int i=(r);i>=(l);i--)
#define pii pair<int,int>
using namespace std;

typedef long long ll;
typedef double db;
typedef __int128 i128;

int n,m;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>n>>m;
    vector<vector<int> > inv(m+1);
    vector<int> cnt(n+1);
    vector<ll> sum(m+3); // 差分，注意开空间
    rep(i,1,n)
    {
        int a,b;
        cin>>a>>b;
        inv[a].push_back(i);
        inv[b].push_back(i);
    }
    int l=1,r=1;
    int k=n;
    while(l<=m)
    {
        while(r<=m&&k!=0)
        {
            for(auto i:inv[r])
            {
                if(cnt[i]==0) k--; // 如果没被占用。
                cnt[i]++; // 占用。
            }
            r++;
        }
        if(k!=0) break; // 这玩意儿根本搞不起来，因为 r 到 m 了都不行，l 到后面更不行。
        sum[r-l]++,sum[m-l+2]--;
        // 这里相当于将 [l-r+1,m-l+1] 这个区间全部 +1。
        for(auto i:inv[l])
        {
            cnt[i]--;
            if(cnt[i]==0) k++;
        } // 还原，就是将 l 右移，故需做还原操作。
        l++;
    }
    sum[0]=0;
    rep(i,1,m)
    {
        sum[i]+=sum[i-1];
        cout<<sum[i]<<' ';
    }
}

// hope to debug successfully