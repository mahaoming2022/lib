#include <bits/stdc++.h>

using namespace std;

vector<int> a;
vector<int> b;
vector<int> c;

string ast,bst;

int main()
{
    cin>>ast>>bst;
    int len1=ast.size(),len2=bst.size();
    for(int i=len1-1;i>=0;--i)
        a.push_back(ast[i]-'0');
    for(int i=len2-1;i>=0;--i)
        b.push_back(bst[i]-'0');
    int jw=0;
    for(int i=0;i<max(len1,len2);++i)
    {
        if(i<len1)
            jw+=a[i];
        if(i<len2)
            jw+=b[i];
        c.push_back(jw%10);
        jw/=10;
    }
    if(jw) 
        c.push_back(jw);
    for(int i=c.size()-1;i>=0;--i)
        cout<<c[i];
}
