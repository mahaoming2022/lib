#include <bits/stdc++.h>

using namespace std;

vector<int> a;
vector<int> b;
vector<int> c;

string ast,bst;

int main()
{
    cin>>ast>>bst;
	string tmp;
	tmp=ast;
	reverse(ast.begin(),ast.end());
	ast=tmp+ast;
	tmp=bst;
	reverse(bst.begin(),bst.end());
	bst=tmp+bst;
    int len1=ast.size(),len2=bst.size();
    int len3=len1+len2;
    c.resize(len3,0);
	for(int i=len1-1;i>=0;--i)
        a.push_back(ast[i]-'0');
	for(int i=len2-1;i>=0;--i)
        b.push_back(bst[i]-'0');
    for(int i=0;i<len1;i++)
        for(int j=0;j<len2;j++)
            c[i+j]+=a[i]*b[j];
    for(int i=0;i<len3;++i)
        if(c[i]>=10)
        {
            c[i+1]+=c[i]/10;
            c[i]%=10;
        }
    while(c.size()>1&&c.back()==0)
        c.pop_back();
    for(int i=c.size()-1;i>=0;--i)
        cout<<c[i];
}
