#include <bits/stdc++.h>

using namespace std;

#define MAXN 1024

struct Point{
	int x,y;
};

struct Line{
	int pair,num;
};

bool cmp_pair(Line a,Line b){
	return a.pair>b.pair;
}

bool cmp_num(Line a,Line b){
	return a.num<b.num;
}

int m,n;
Line row[MAXN],col[MAXN];

int main(){
	//freopen("chairs.in","r",stdin);
	//freopen("chairs.out","w",stdout);
	int k,l,d;
	cin>>m>>n>>k>>l>>d;
	for(int i=1;i<=d;i++){
		Point a,b;
		scanf("%d %d %d %d",&a.x,&a.y,&b.x,&b.y);
		if(a.x==b.x){
			col[min(a.y,b.y)].pair++;
			col[min(a.y,b.y)].num=min(a.y,b.y);
		}
		else if(a.y==b.y){
			row[min(a.x,b.x)].pair++;
			row[min(a.x,b.x)].num=min(a.x,b.x);
		}
	}
	sort(row+1,row+m,cmp_pair);
	sort(row+1,row+1+k,cmp_num);
	for(int i=1;i<=k;i++){
		printf("%d ",row[i].num);
	}
	return 0;
}
