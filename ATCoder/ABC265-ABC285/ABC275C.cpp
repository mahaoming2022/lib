#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)

using namespace std;
typedef long long ll;
typedef double db;

char a[10][10];
set<pair<int,int> > pt;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif  
    int ans=0;
    rep(i,1,9)
		rep(j,1,9)
        {
			cin>>a[i][j];
			if(a[i][j]=='#')
				pt.insert({i,j});
		} 
	for(auto i : pt){
		for(auto j : pt){
			if(i!=j){
				int x=(i.second-j.second),y=(i.first-j.first);
				if(pt.find({i.first+x,i.second-y})!=pt.end()&&pt.find({j.first+x,j.second-y})!=pt.end())ans++;
            }
            // 弦图
		}
	}
	cout<<ans/4;
}