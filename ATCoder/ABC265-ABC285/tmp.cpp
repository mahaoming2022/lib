#include<bits/stdc++.h>
using namespace std;

inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}

void print(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);
	putchar(x%10^48);
}

const int N=2e5+5;
int n,m,a[N],b[N],pos[N],now;

int main(){
	n=read(),m=read(),now=1;
	for(int i=1;i<=m;++i)a[i]=read();
	for(int i=1;i<=n;++i)b[i]=i;
	for(int i=1;i<=m;++i)swap(b[a[i]],b[a[i]+1]);
	for(int i=1;i<=n;++i)pos[b[i]]=i,b[i]=i;
	for(int i=1;i<=m;++i){
		if(b[a[i]]==1)print(pos[b[a[i]+1]]),puts("");
		else if(b[a[i]+1]==1)print(pos[b[a[i]]]),puts("");
		else print(pos[1]),puts("");
		swap(b[a[i]],b[a[i]+1]);
	}
	return 0;
}