#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)

using namespace std;
typedef long long ll;
typedef double db;

unordered_map<int,set<int> > line,col;

int n;
int h,w,x,y;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif  
    cin>>h>>w>>x>>y>>n;
    rep(i,1,n)
    {
       int xx,yy;
       cin>>xx>>yy;
       line[xx].insert(yy);
       col[yy].insert(xx); 
    }
    int Q;
    cin>>Q;
    while(Q--)
    {
        // init
        line[x].insert(0);line[x].insert(w+1);
        col[y].insert(0);col[y].insert(h+1);
        char o;int d,pos;
        cin>>o>>d;
        if(o=='L')
        {
            pos=*prev(line[x].lower_bound(y));
            y=max(pos+1,y-d);if(y<0) y=0;
        }
        if(o=='R')
        {
            pos=*(line[x].upper_bound(y));
            y=min(pos-1,y+d);
        }
        if(o=='U')
        {
            pos=*prev(col[y].lower_bound(x));
            x=max(pos+1,x-d);if(x<0) x=0;
        }
        if(o=='D')
        {
            pos=*(col[y].upper_bound(x));
            x=min(pos-1,x+d);
        }
        cout<<x<<' '<<y<<endl;
    }
}