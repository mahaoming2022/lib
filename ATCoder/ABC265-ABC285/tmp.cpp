/*R()函数是快读函数，write()函数是快输函数*/
#define rep(a,b,c) for(int a=b;a<=c;a++)
#define per(a,b,c) for(int a=b;a>=c;a--)
const int N=1e3+5;
const int dx[5]={0,1,-1,0,0},dy[5]={0,0,0,1,-1};
int n,m,a[N][N];
int f[N][2][2][2];
int box[3][N];
bool check(int l,int x,int y,int z){
	rep(i,1,m){
		if(l-2>=1) box[0][i]=a[l-2][i]^z;
		else box[0][i]=2; 
	}
	rep(i,1,m) box[1][i]=a[l-1][i]^y;
	rep(i,1,m){
		if(l<=n) box[2][i]=a[l][i]^x;
		else box[2][i]=2;
	}
    //这里为了方便将要检查的三行放到一个 3×m 的数组里。
	rep(i,1,m){
		bool flag=0;
		rep(k,1,4){
			int tx=1+dx[k],ty=i+dy[k];
			if(ty<1||ty>m||box[tx][ty]==2) continue;
			if(box[1][i]==box[tx][ty]){
				flag=1;
				break; 
			}
		}
		if(!flag) return 0;
	}
	return 1;
}
int main(){
	n=R(),m=R();
	rep(i,1,n)rep(j,1,m)a[i][j]=R(); 
	memset(f,0x3f,sizeof(f));
	f[1][0][0][0]=0,f[1][1][0][0]=1;
	rep(i,2,n){
		rep(x,0,1){//自己本身 
			rep(y,0,1){//前面一行 
				rep(z,0,1){//再前面一行 
					if(check(i,x,y,z)){
						f[i][x][y][z]=min(f[i][x][y][z],min(f[i-1][y][z][0],f[i-1][y][z][1])+x);
					}
				}
			}
		}
	}
	int ans=0x3f3f3f3f;
	rep(x,0,1){
		rep(y,0,1){
			rep(z,0,1){
				if(check(n+1,0,x,y)) ans=min(ans,f[n][x][y][z]);
			}
		}
	}
	if(ans!=0x3f3f3f3f) write(ans);
	else puts("-1");
}
