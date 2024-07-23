#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=1e5+24;
const int mod=10007;
int n;
string s;
int c1[N],c2[N],l1[N],l2[N];

inline pair<int,int> dfs(int l,int r)
{
    if(l>r) return {1,1};
    if(l1[r]>=l) // it is or
    {
        int pos=l1[r];
        pair<int,int> ansl=dfs(l,pos-1),ansr=dfs(pos+1,r);
        int ans1=ansl.first,ans2=ansl.second;
        int ans3=ansr.first,ans4=ansr.second;
        int ansf=ans1*ans3,anst=ans1*ans4+ans2*ans3+ans2*ans4;
        return make_pair(ansf%mod,anst%mod);
    }
    if(l2[r]>=l)
    {
        int pos=l2[r];
        pair<int,int> ansl=dfs(l,pos-1),ansr=dfs(pos+1,r);
        int ans1=ansl.first,ans2=ansl.second;
        int ans3=ansr.first,ans4=ansr.second;
        int anst=ans1*ans3,ansf=ans1*ans4+ans2*ans3+ans2*ans4;
        return make_pair(ansf%mod,anst%mod);
    }
    else return dfs(l+1,r-1);
}

int main()
{
    freopen("exp.in","r",stdin);
    freopen("exp.out","w",stdout);
    cin>>n>>s;
    s=' '+s;
    int lev=0;
    for(int i=1;i<=n;++i)
    {
        if(s[i]=='(') lev++;
        if(s[i]==')') lev--;
        if(s[i]=='+') c1[lev]=i;
        if(s[i]=='*') c2[lev]=i;
        l1[i]=c1[lev],l2[i]=c2[lev];
    }
    cout<<dfs(1,n).first;
}