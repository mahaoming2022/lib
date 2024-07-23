#include <bits/stdc++.h>

using namespace std;

const int N=1e5+24;
const int mod=10007;

int L;
char str[N];
int c1[N],c2[N],l1[N],l2[N];

inline pair<int,int> dfs(int l,int r)
{
    pair<int,int> ans;
    if(l>r)
    {
        ans.first=1; //0
        ans.second=1; //1
        return ans;
    }
    if(l1[r]>=l) //or
    {
        pair<int,int> ansl=dfs(l,l1[r]-1);
        pair<int,int> ansr=dfs(l1[r]+1,r);
        
        ans.first=(ansl.first*ansr.first);ans.first%=mod;
        ans.second=(ansl.first*ansr.second+ansl.second*ansr.first+ansl.second*ansr.second);ans.second%=mod;
        return ans;
    }
    if(l2[r]>=l) //and
    {
        pair<int,int> ansl=dfs(l,l2[r]-1);
        pair<int,int> ansr=dfs(l2[r]+1,r);
        
        ans.second=(ansl.second*ansr.second);ans.second%=mod;
        ans.first=(ansl.first*ansr.second+ansl.second*ansr.first+ansl.first*ansr.first);ans.first%=mod;
        return ans;
    }
    else 
        return dfs(l+1,r-1);
}

int main()
{
    cin>>L;
    scanf("%s",str+1);
    int x=0;
    for(int i=1;i<=L;++i)
    {
        if(str[i]=='(')
            x+=1;
        else if(str[i]==')')
            x-=1;
        else if(str[i]=='+')
            c1[x]=i;
        else if(str[i]=='*')
            c2[x]=i;
        l1[i]=c1[x];
        l2[i]=c2[x];
    }
    cout<<dfs(1,L).first;
}
