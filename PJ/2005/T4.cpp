#include <bits/stdc++.h>

using namespace std;

vector<int> l,q,p,r,n;

int k;
string nst;

vector<int> mult(vector<int> a,vector<int> b)
{
    vector<int> c;
    int len1=min(k,(int)a.size());
    int len2=min(k,(int)b.size());
    int len3=len1+len2;
    c.resize(len3,0);
    for(int i=0;i<len1;++i)
        for(int j=0;j<len2;++j)
            c[i+j]+=a[i]*b[j];
    for(int i=0;i<len3;++i)
        if(c[i]>=10)
        {
            c[i+1]+=c[i]/10;
            c[i]%=10;
        }
    while(c.size()>1&&c.back()==0)
        c.pop_back();
    return c;
}

vector<int> smult(vector<int> a,int b)
{
    vector<int> c;
    int jw=0;
    for(int i=0;i<a.size()||jw;++i)
    {
        if(i<a.size())
            jw+=a[i]*b;
        c.push_back(jw%10);
        jw/=10;
    }   
    while(c.size()>1&&c.back()==0)
        c.pop_back();
    return c;
}

int main()
{
    cin>>nst>>k;
    for(int i=nst.size()-1;i>=0;--i)
        n.push_back(nst[i]-'0');
    l.push_back(1);
    q=n;
    for(int i=1;i<=k;++i)
    {
        p=n;
        r.clear();r.push_back(1);
        bool found=0;
        for(int j=1;j<=10;++j){
            p=mult(p,q);
            r=mult(r,q);
            if(p[i-1]==n[i-1])
            {
                // vector<int> tmpj;
                // tmpj.clear();
                // tmpj.push_back(j);
                // l=mult(l,tmpj);
                l=smult(l,j);
                q=r;
                found=1;
                break;
            }
        }
        if(!found)
        {
            cout<<-1;
            return 0;
        }
    }
    for(int i=l.size()-1;i>=0;i--)
        cout<<l[i];
}
