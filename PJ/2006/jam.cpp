#include <bits/stdc++.h>

using namespace std;

int s,t,w;
char jam[48];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    cin>>s>>t>>w;
    scanf("%s",jam+1);
    int times=5;
    while(times--){
        bool fg=0;
        for(int i=w;i>=1;--i)
            if(jam[i]+1+w-i<=t+96)
            {
                jam[i]++;
                for(int j=i+1;j<=w;++j)
                    jam[j]=jam[j-1]+1;
                fg=1;
                break;
            }
        if(!fg)
            break;
        for(int j=1;j<=w;++j)
            cout<<jam[j];
        cout<<endl;
    }
}
