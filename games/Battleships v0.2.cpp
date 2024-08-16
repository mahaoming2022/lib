#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

int B[10]= {1,3,2,1};
bool isAI=false;
int n=7,m=7;
int a[2][105][105];
string Pame[2];

pair<pair<int,int>,bool> AI_canplace[10005];
int AI_canplace_cnt=0;
int AI_brain[105][105];
void welcome()
{
    system("cls");
    cout<<"欢迎来到海战棋v0.2！\n";
    cout<<"灵感：MasonXu    代码：MasonXu\n";
    cout<<"A - 开始双人对战\n";
    cout<<"B - 开始人机对战\n";
    cout<<"C - 说明&设置\n";
    char key=getch();
    if(key=='b')
        isAI=true;
    if(key=='a' || key=='b')
        return;
Reset:
    system("cls");
    cout<<"规则：自己搜，懒得写了\n";
    cout<<"本次(v0.2)更新内容：\n";
    cout<<" (1) 随机布置盘面\n";
    cout<<" (2) 人机对战模式\n";
    cout<<"A - 行数:"<<n<<"\n";
    cout<<"B - 列数:"<<m<<"\n";
    for(int i=1; i<=9; i++)
    {
        cout<<(char)('B'+i)<<" - 每人1x"<<i<<"船数:"<<B[i]<<"\n";
    }
    cout<<"按A~K进行设置\n";
    cout<<"按其他任意键回到主界面\n";
    key=getch();
    if(key>='a' && key<='k')
    {
        if(key=='a')
        {
            cout<<"设置为多少？\n";
            cin>>n;
        }
        else if(key=='b')
        {
            cout<<"设置为多少？\n";
            cin>>m;
        }
        else
        {
            cout<<"设置为多少？\n";
            cin>>B[key-'b'];
        }
        goto Reset;
    }
    welcome();
}
int main()
{
    srand((unsigned)time(NULL));
    system("title Battleships");
    welcome();
    int op=0;
    cout<<"玩家1名字：\n";
    cin>>Pame[0];
    cout<<"玩家2名字：\n";
    cin>>Pame[1];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            a[0][i][j]=a[1][i][j]=0;
    for(int ma=0; ma<2; ma++)
    {
        if(isAI && ma==1)
        {
Randomplace:
            int tp[10];
            for(int i=1; i<10; i++)
                tp[i]=B[i];
            for(int i=9; i>=1; i--)
            {
                while(tp[i]--)
                {
                    AI_canplace_cnt=0;
                    for(int ii=1; ii<=n; ii++)
                        for(int jj=1; jj<=n-i+1; jj++)
                        {
                            bool flag=true;
                            for(int i4=ii,j4=jj; i4<ii+i && j4<jj+i; j4++)
                            {
                                for(int i3=i4-1; i3<=i4+1; i3++)
                                    for(int j3=j4-1; j3<=j4+1; j3++)
                                        if(a[ma][i3][j3]==1)
                                            flag=false;
                            }
                            if(flag)
                            {
                                AI_canplace[++AI_canplace_cnt]= {{ii,jj},0};
                            }
                        }
                    for(int ii=1; ii<=n-i+1; ii++)
                        for(int jj=1; jj<=n; jj++)
                        {
                            bool flag=true;
                            for(int i4=ii,j4=jj; i4<ii+i && j4<jj+i; i4++)
                            {
                                for(int i3=i4-1; i3<=i4+1; i3++)
                                    for(int j3=j4-1; j3<=j4+1; j3++)
                                        if(a[ma][i3][j3]==1)
                                            flag=false;
                            }
                            if(flag)
                            {
                                AI_canplace[++AI_canplace_cnt]= {{ii,jj},1};
                            }
                        }
                    int rant=rand()%AI_canplace_cnt+1;
                    int px=AI_canplace[rant].first.first;
                    int py=AI_canplace[rant].first.second;
                    if(AI_canplace[rant].second==0)
                    {
                        for(int ii=py; ii<py+i; ii++)
                            a[ma][px][ii]=1;
                    }
                    else
                    {
                        for(int ii=px; ii<px+i; ii++)
                            a[ma][ii][py]=1;
                    }
                }
            }
            continue;
        }
        system("cls");
        cout<<"现在由"<<Pame[ma]<<"布置棋盘\n";
        getch();
        system("cls");
        cout<<"是否使用随机布置？\n";
        cout<<"是(A) 否(B)\n";
        char _key=getch();
        if(_key=='a')
        {
            goto Randomplace;
        }
        int tp[10];
        for(int i=1; i<10; i++)
            tp[i]=B[i];
        for(int i=9; i>=0; i--)
        {
            while(tp[i]--)
            {
Replace:
                system("cls");
                if(i>0)
                    cout<<"放置1x"<<i<<"的船：\n";
                cout<<"  ";
                for(int ii=1; ii<=m; ii++)
                {
                    cout<<ii;
                    if(ii<10)
                        cout<<" ";
                }
                cout<<"\n";
                for(int ii=1; ii<=n; ii++)
                {
                    cout<<(char)('A'+ii-1)<<" ";
                    for(int jj=1; jj<=m; jj++)
                    {
                        if(a[ma][ii][jj]==1)
                            cout<<"@";
                        else
                            cout<<".";
                        if(a[ma][ii][jj]==1 && a[ma][ii][jj+1]==1)
                            cout<<"=";
                        else
                            cout<<" ";
                    }
                    cout<<"\n";
                }
                if(i==0)
                {
                    getch();
                    break;
                }
                cout<<"输入该船左上角坐标：\n";
                int x,y;
                char _TEMP;
                cin>>_TEMP>>y;
                x=(_TEMP>='A' && _TEMP<='Z'?_TEMP-'A'+1:_TEMP-'a'+1);
                if(x<1 || x>n || y<1 || y>m)
                {
                    cout<<"坐标超出边界！\n";
                    getch();
                    goto Replace;
                }
                if(i==1)
                {
                    _TEMP='H';
                }
                else
                {
                    cout<<"输入横向(H)竖向(S)\n";
                    cin>>_TEMP;
                }
                if(_TEMP!='H' && _TEMP!='S')
                {
                    cout<<"请输入大写字母H或S\n";
                    getch();
                    goto Replace;
                }
                if(_TEMP=='H' && y+i-1>m || _TEMP=='S' && x+i-1>n)
                {
                    cout<<"坐标超出边界！\n";
                    getch();
                    goto Replace;
                }
                bool flag=true;
                for(int ii=x,jj=y; ii<x+i && jj<y+i; _TEMP=='H'?jj++:ii++)
                {
                    for(int i3=ii-1; i3<=ii+1; i3++)
                        for(int j3=jj-1; j3<=jj+1; j3++)
                            if(a[ma][i3][j3]==1)
                                flag=false;
                }
                if(!flag)
                {
                    cout<<"该船不能和已有的船重叠，相邻或对角相邻！\n";
                    getch();
                    goto Replace;
                }
                for(int ii=x,jj=y; ii<x+i && jj<y+i; _TEMP=='H'?jj++:ii++)
                {
                    a[ma][ii][jj]=1;
                }
            }
        }
    }
    while(true)
    {
        if(op==0 || !isAI)
        {
            if(!isAI)
            {
                system("cls");
                cout<<"现在由"<<Pame[op]<<"操作";
                getch();
            }
Reattark:
            system("cls");
            cout<<"你的棋盘：\n";
            cout<<"  ";
            for(int ii=1; ii<=m; ii++)
            {
                cout<<ii;
                if(ii<10)
                    cout<<" ";
            }
            cout<<"\n";
            for(int ii=1; ii<=n; ii++)
            {
                cout<<(char)('A'+ii-1)<<" ";
                for(int jj=1; jj<=m; jj++)
                {
                    if(a[op][ii][jj]==1)
                        cout<<"@";
                    else if(a[op][ii][jj]==2)
                        cout<<"~";
                    else if(a[op][ii][jj]==3)
                        cout<<"O";
                    else
                        cout<<".";
                    if(a[op][ii][jj]%2==1 && a[op][ii][jj+1]%2==1)
                        cout<<"=";
                    else
                        cout<<" ";
                }
                cout<<"\n";
            }
            cout<<Pame[!op]<<"的棋盘：\n";
            cout<<"  ";
            for(int ii=1; ii<=m; ii++)
            {
                cout<<ii;
                if(ii<10)
                    cout<<" ";
            }
            cout<<"\n";
            for(int ii=1; ii<=n; ii++)
            {
                cout<<(char)('A'+ii-1)<<" ";
                for(int jj=1; jj<=m; jj++)
                {
                    if(a[!op][ii][jj]==2)
                        cout<<"~";
                    else if(a[!op][ii][jj]==3)
                        cout<<"O";
                    else
                        cout<<".";
                    if(a[!op][ii][jj]==3 && a[!op][ii][jj+1]==3)
                        cout<<"=";
                    else
                        cout<<" ";
                }
                cout<<"\n";
            }
            int x,y;
            char _TEMP;
            cin>>_TEMP>>y;
            x=(_TEMP>='A' && _TEMP<='Z'?_TEMP-'A'+1:_TEMP-'a'+1);
            if(x<1 || x>n || y<1 || y>m)
            {
                cout<<"坐标超出边界！\n";
                getch();
                goto Reattark;
            }
            if(a[!op][x][y]%2==1)
            {
                cout<<"击中！\n";
                a[!op][x][y]=3;
                a[!op][x-1][y-1]=2;
                a[!op][x+1][y-1]=2;
                a[!op][x-1][y+1]=2;
                a[!op][x+1][y+1]=2;
            }
            else
            {
                cout<<"未击中\n";
                a[!op][x][y]=2;
            }
            getch();
        }
        else
        {
            system("cls");
            cout<<Pame[!op]<<"的棋盘：\n";
            cout<<"  ";
            for(int ii=1; ii<=m; ii++)
            {
                cout<<ii;
                if(ii<10)
                    cout<<" ";
            }
            cout<<"\n";
            for(int ii=1; ii<=n; ii++)
            {
                cout<<(char)('A'+ii-1)<<" ";
                for(int jj=1; jj<=m; jj++)
                {
                    if(a[!op][ii][jj]==1)
                        cout<<"@";
                    else if(a[!op][ii][jj]==2)
                        cout<<"~";
                    else if(a[!op][ii][jj]==3)
                        cout<<"O";
                    else
                        cout<<".";
                    if(a[!op][ii][jj]%2==1 && a[!op][ii][jj+1]%2==1)
                        cout<<"=";
                    else
                        cout<<" ";
                }
                cout<<"\n";
            }
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=m; j++)
                {
                    AI_brain[i][j]=0;
                }
            }
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=m; j++)
                {
                    if(a[!op][i][j]==3)
                    {
                        if(a[!op][i][j-1]!=3 && a[!op][i+1][j]!=3 && a[!op][i][j+1]!=3)
                            AI_brain[i-1][j]=100;
                        if(a[!op][i-1][j]!=3 && a[!op][i+1][j]!=3 && a[!op][i][j+1]!=3)
                            AI_brain[i][j-1]=100;
                        if(a[!op][i-1][j]!=3 && a[!op][i][j-1]!=3 && a[!op][i][j+1]!=3)
                            AI_brain[i+1][j]=100;
                        if(a[!op][i-1][j]!=3 && a[!op][i][j-1]!=3 && a[!op][i+1][j]!=3)
                            AI_brain[i][j+1]=100;
                    }
                }
            }
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=m; j++)
                {
                    int cnt=0;
                    for(int ii=max(i-1,1); ii<=min(i+1,n); ii++)
                    {
                        for(int jj=max(j-1,1); jj<=min(j+1,m); jj++)
                        {
                            if(a[!op][ii][jj]<2)
                                cnt++;
                        }
                    }
                    AI_brain[i][j]+=cnt*cnt;
                }
            }
            int ransum=0;
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=m; j++)
                {
                    if(a[!op][i][j]>1)
                        AI_brain[i][j]=0;
                    ransum+=AI_brain[i][j];
                }
            }
            int ranx=rand()*rand()%ransum;
            int hitx=-1,hity=-1;
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=m; j++)
                {
                    if(ranx<AI_brain[i][j])
                    {
                        hitx=i,hity=j;
                        break;
                    }
                    else
                        ranx-=AI_brain[i][j];
                }
                if(hitx>0)
                    break;
            }
            cout<<Pame[op]<<"选择攻击"<<(char)(hitx+'A'-1)<<hity<<"!\n";
            if(a[!op][hitx][hity]%2==0)
            {
                cout<<"未击中\n";
                a[!op][hitx][hity]=2;
            }
            else
            {
                cout<<"击中！\n";
                a[!op][hitx][hity]=3;
                a[!op][hitx-1][hity-1]=2;
                a[!op][hitx+1][hity-1]=2;
                a[!op][hitx-1][hity+1]=2;
                a[!op][hitx+1][hity+1]=2;
            }
            getch();
        }
        bool winflag=true;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                if(a[!op][i][j]==1)
                    winflag=false;
        if(winflag)
        {
            cout<<Pame[!op]<<"的所有战舰均被击沉！\n";
            cout<<Pame[op]<<"获胜！！";
            break;
        }
        op=!op;
    }
    return 0;
}