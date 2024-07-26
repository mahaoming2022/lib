#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)

using namespace std;

typedef long long ll;
typedef double db;

string s1,s2;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>s1>>s2;
    int len1=s1.size()+1,len2=s2.size()+1;
    s1=' '+s1,s2=' '+s2;
    int p1=1,p2=1;
    while(p1<len1&&p2<len2)
    {
        int l1=p1,l2=p2;
        while(s1[p1+1]==s1[p1]) p1++;
        while(s2[p2+1]==s2[p2]) p2++;
        if(p1-l1>p2-l2||s1[l1]!=s2[l2]||(p1==l1&&p2!=l2))
        {
            cout<<"No"<<endl; return 0;
        }
        p1++,p2++;
    }
    if(p1<len1||p2<len2) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
} 

// debug
// line 18 加一。