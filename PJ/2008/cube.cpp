#include <bits/stdc++.h>

using namespace std;

int m,n;
int a[52][52];
char buf[520][520];
const char cube[10][10]=
{
    "..+---+",
    "./   /|",
    "+---+ |",
    "|   | +",
    "|   |/.",
    "+---+.."
};

void draw(int x,int y)
{
    for(int i=0;i<6;++i)
        for(int j=0;j<7;++j)
            if(cube[6-i-1][j]!='.')
                buf[x-i][y+j]=cube[6-i-1][j];
}

int main()
{
    cin>>m>>n;
    int l=4*n+2*m+1;
    int k=0;
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j){
            cin>>a[i][j];
            k=max(k,a[i][j]*3+2*(m-i+1)+1);
        }
    for(int i=1;i<=k;++i)
        for(int j=1;j<=l;++j)
            buf[i][j]='.';
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j)
        {
            int x=k-2*(m-i);
            int y=2*(m-i)+4*(j-1)+1;
            while(a[i][j]--)
            {
                draw(x,y);
                x-=3;
            }
        }
    for(int i=1;i<=k;++i)
    {
        for(int j=1;j<=l;++j)
            cout<<buf[i][j];
        cout<<endl;
    }
}
