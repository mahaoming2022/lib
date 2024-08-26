#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)

using namespace std;

int n;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    list<int> a;
    rep(i,1,n) a.push_back(i);
    int ans1=0,ans2=0;
    while(!a.empty())
    {
        int cnt=0;
        ans1++;
        int sz=a.size();
        while(cnt<sz)
        {
            cnt++;
            int f=a.front();
            a.pop_front();
            if(cnt%3!=1)
                a.push_back(f);
            if(cnt%3==1&&f==n)
                ans2=ans1;
        }
    }
    cout<<ans1<<' '<<ans2;
}