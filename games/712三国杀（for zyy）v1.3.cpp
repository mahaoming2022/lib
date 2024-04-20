#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;

void welcome()
{
    system("cls");
    cout<<"欢迎来到712三国杀（1.3）！\n";
    cout<<"灵感：xxmzhuyuyang & MasonXu     代码：MasonXu\n";
    cout<<"A-卡牌介绍	B-开始游戏\n";
    char key=getch();
    if(key=='a')
    {
        cout<<"本次更新内容：卡牌等级，幸运草，角色徐慕熹\n";
        cout<<"1. 卡牌介绍 (共42张)\n";
        cout<<"(1) 内卷*8 使自己成绩+8\n";
        cout<<"(2) 摆烂*8 抵消'干扰'效果\n";
        cout<<"(3) 干扰*10 使任意玩家成绩-8\n";
        cout<<"(4) 听写*4 除自己外所有玩家要么出1张'干扰'，要么成绩-8\n";
        cout<<"(5) 考试*4 除自己外所有玩家要么出1张'内卷'，要么成绩-8\n";
        cout<<"(6) 内卷禁令*2 所有玩家不可主动出'内卷'，持续1回合\n";
        cout<<"(7) 制裁卷怪*2 使成绩最高者成绩-8\n";
        cout<<"(8) 鼓励摆烂*2 使成绩最低者成绩+8\n";
        cout<<"(9) 幸运草*2 有概率抽到高级卡牌\n";
        cout<<"2. 基本规则\n";
        cout<<"每人初始150分，满分150分，分数小于90分被淘汰\n";
        cout<<"每人初始4张随机牌，所有人轮流出牌，每人在回合开始抽2张牌\n";
        cout<<"每人在自己回合可以出任意多的干扰，但只能出一次内卷\n";
        cout<<"且回合结束时只能保留3张牌\n";
        cout<<"3.角色\n";
        cout<<"(1) 吴诺\n";
        cout<<"究极卷王：对内卷已经练得自如的她自己使用内卷额外再加4分\n";
        cout<<"(2) 朱煜洋\n";
        cout<<"疯批：使用干扰时，干扰对象分数额外-4\n";
        cout<<"(3) 徐慕熹\n";
        cout<<"无限RP：没有幸运草时视为有C级幸运草，有幸运草时幸运草等级视为+1\n";
        cout<<"数学大佬：无视考试\n";
        getch();
        welcome();
    }
}
int n;
string name[1005];
bool alive[1005];
int score[1005];
int cn[1005],hold[1005][1005];
int holdlv[1005][1005];
int leftn;
bool isAI[1005];
int role[1005];
int luck[1005];

string rolename[1005]= {"","吴诺","朱煜洋","徐慕熹"};
int zazz[1005]= {0,8,8,10,4,4,2,2,2,4};
int lvchance[1005]= {0,100,40,30,20,10,3,2,1,0,0};
bool fsuc;
void maydied(int x)
{
    if(score[x]<90)
    {
        cout<<name[x]<<"分数不足90，被xb击毙了！\n";
        leftn--;
        alive[x]=false;
    }
}
void randcard(int x,int rep)
{
    int TT=rand()%44+1;
    int KK=114514;
    for(int i=1; i<=9; i++)
        if(TT<=zazz[i])
        {
            KK=i;
            break;
        }
        else
            TT-=zazz[i];
    hold[x][++cn[x]]=KK;
    TT=rand()%100+1;
    int mut=1;
    int tmp_should=luck[x]+1;
    if(role[x]==3)
        tmp_should++;
    for(int i=luck[x]+1; i>=0; i--)
        if(TT<=lvchance[i]*mut)
        {
            KK=i;
            break;
        }
        else
            TT-=lvchance[i]*mut,mut*=2;
    holdlv[x][cn[x]]=KK;
    if(rep>1)
        randcard(x,rep-1);
}
void gpause(int x)
{
    if(isAI[x])
        Sleep(500);
    else
        getch();
}
void ppause(int x)
{
    system("cls");
    cout<<"下面由 "<<name[x]<<" 操作\n";
    gpause(x);
}

void spendcard(int x,int y)
{
    for(int i=y; i<cn[x]; i++)
        hold[x][i]=hold[x][i+1],holdlv[x][i]=holdlv[x][i+1];
    cn[x]--;
    fsuc=true;
}

void nameof(int x,int y)
{
    string tmp1[14]= {"","内卷","摆烂","干扰","听写","考试","内卷禁令","制裁卷怪","鼓励摆烂","幸运草"};
    cout<<tmp1[x];
    string tmp2[14]= {"","C","Un","R","E","L","M","Ul","S"};
    if(y>1)
        cout<<"["<<tmp2[y]<<"]";
}
int main()
{
    srand((unsigned)time(NULL));
    welcome();
    cout<<"请输入人数：\n";
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cout<<"请输入玩家"<<i<<"姓名：\n";
        cin>>name[i];
        score[i]=150;
        randcard(i,2);
        alive[i]=true;
        cout<<name[i]<<"是否使用AI托管?(Y/N)\n";
        char key=getch();
        if(key=='y')
            isAI[i]=true;
        if(name[i]=="WUNUO111" || name[i]=="wunuo")
        {
            role[i]=1;
            continue;
        }
        if(name[i]=="xxmzhuyuyang" || name[i]=="zhuyuyang")
        {
            role[i]=2;
            continue;
        }
        if(name[i]=="MasonXu" || name[i]=="xumuxi")
        {
            role[i]=3;
            continue;
        }
        int tmp_rand=rand()%10;
        if(1<=tmp_rand && tmp_rand<=3)
            role[i]=tmp_rand;
        else
            role[i]=0;
    }
    int I=1;
    int neijuanjl=0;
    leftn=n;
    while(leftn>1)
    {
        while(!alive[I])
        {
            I=I%n+1;
            if(I==neijuanjl)
                neijuanjl=0;
        }
        randcard(I,2);
        char key;
        bool juaned=false;
        int wantt,wantk,wantlv;
        int fcnt=0;
        ppause(I);
startout:
        ;
        system("cls");
        cout<<"当前是 "<<name[I]<<" 的回合";
        if(isAI[I])
            cout<<"（该玩家正在被AI托管）";
        cout<<"\n玩家：\n";
        fsuc=false;
        for(int i=1; i<=n; i++)
        {
            if(alive[i])
            {
                cout<<name[i];
                if(role[i]>0)
                    cout<<"["<<rolename[role[i]]<<"]";
                cout<<": "<<score[i]<<"/150\n";
            }
        }
        if(neijuanjl)
            cout<<name[neijuanjl]<<"正在使用内卷禁令\n";
        cout<<"卡牌：\n";
        cout<<cn[I]<<endl;
        for(int i=1; i<=cn[I]; i++)
        {
            int t=hold[I][i];
            nameof(t,holdlv[I][i]);
            cout<<"("<<(char)('A'+i-1)<<")\t";
        }
        cout<<"\n";
        cout<<"请选择要出的牌（结束回合按0）：\n";
        if(!isAI[I])
            key=getch();
        else
        {
            Sleep(500);
            if(cn[I]==0 || fcnt>=3)
                key='0';
            else
                key='a'+rand()%cn[I];
        }
        if(key=='0')
        {
            luck[I]=0;
            for(int i=1; i<=cn[I]; i++)
                if(hold[I][i]==9)
                    luck[I]=max(luck[I],holdlv[I][i]);
qip:
            ;
            if(cn[I]>3)
            {
                system("cls");
                cout<<"请弃掉"<<cn[I]-3<<"张牌\n";
                for(int i=1; i<=cn[I]; i++)
                {
                    int t=hold[I][i];
                    nameof(t,holdlv[I][i]);
                    cout<<"("<<(char)('A'+i-1)<<")\t";
                }
                if(!isAI[I])
                    key=getch();
                else
                {
                    Sleep(500);
                    key='a';
                    if(hold[I][1]==9 && holdlv[I][1]==luck[I])
                        key='b';
                }
                wantt=key-'a'+1;
                wantk=hold[I][wantt];
                if(wantt<1 || wantt>cn[I])
                    goto qip;
                cout<<"你弃掉了";
                nameof(wantk,holdlv[I][wantt]);
                spendcard(I,wantk);
                cout<<"\n";
                gpause(I);
                goto qip;
            }
            I=I%n+1;
            if(I==neijuanjl)
                neijuanjl=0;
            continue;
        }
        wantt=key-'a'+1;
        wantk=hold[I][wantt];
        wantlv=holdlv[I][wantt];
        if(wantt<1 || wantt>cn[I])
            goto startout;
        cout<<"已使用";
        nameof(wantk,holdlv[I][wantt]);
        cout<<"\n";
        if(wantk==1)
        {
            if(neijuanjl && neijuanjl!=I)
                cout<<name[neijuanjl]<<"正在使用内卷禁令！\n";
            else if(juaned)
                cout<<"你在本回合已经卷过了！\n";
            else
            {
                int tmp_should=7+wantlv;
                if(role[I]==1)
                {
                    cout<<"触发吴诺技能[究极卷王]，成绩额外+4\n";
                    tmp_should+=4;
                }
                cout<<"成绩+"<<tmp_should<<"\n";
                score[I]+=tmp_should;
                if(score[I]>150)
                    score[I]=150;
                cout<<"目前分数"<<score[I]<<"/150\n";
                juaned=true;
                spendcard(I,wantt);
            }
        }
        if(wantk==2)
            cout<<"不可主动使用摆烂！\n";
        if(wantk==3)
        {
            cout<<"请选择干扰对象：\n";
            int LLt=leftn-1;
            int AIchoose=0;
            for(int i=1; i<=n; i++)
            {
                if(alive[i] && i!=I)
                {
                    cout<<name[i]<<"("<<(char)('A'+i-1)<<")\t";
                    if(isAI[I] && rand()%LLt==0 && AIchoose==0)
                        AIchoose=i;
                    LLt--;
                }
            }
            cout<<"\n";
            char key;
            if(!isAI[I])
                key=getch();
            else
            {
                Sleep(500);
                key='a'+AIchoose-1;
            }
            int ganrao=key-'a'+1;
            spendcard(I,wantt);
            if(ganrao>=1 && ganrao<=n && alive[ganrao] && ganrao!=I)
            {
                bool hasbailan=false;
                int bailanlv=114514;
                for(int i=1; i<=cn[ganrao]; i++)
                {
                    if(hold[ganrao][i]==2)
                    {
                        cout<<name[ganrao]<<"出了一张摆烂，抵消了干扰的效果\n";
                        hasbailan=true;
                        bailanlv=holdlv[ganrao][i];
                        spendcard(ganrao,i);
                        break;
                    }
                }
                if(hasbailan && bailanlv>1)
                {
                    cout<<ganrao<<"使用了";
                    nameof(2,bailanlv);
                    cout<<"，触发反伤效果\n";
                    int tmp_should=(bailanlv+1)/3;
                    cout<<"你的成绩-"<<tmp_should<<"\n";
                    score[I]-=tmp_should;
                    maydied(I);
                }
                if(!hasbailan)
                {
                    int tmp_should=7+wantlv;
                    if(role[I]==2)
                    {
                        cout<<name[ganrao]<<"没有摆烂，触发朱煜洋技能[疯批]，扣分额外+4\n";
                        tmp_should+=4;
                    }
                    cout<<name[ganrao]<<"成绩-"<<tmp_should<<"\n";
                    score[ganrao]-=tmp_should;
                    cout<<name[ganrao]<<"目前分数"<<score[ganrao]<<"/150\n";
                    maydied(ganrao);
                }
            }
        }
        if(wantk==4)
        {
            for(int i=1; i<=n; i++)
            {
                if(!alive[i] || i==I)
                    continue;
                bool hasganrao=false;
                for(int j=1; j<=cn[i]; j++)
                    if(hold[i][j]==1)
                    {
                        cout<<name[i]<<"使用了干扰\n";
                        hasganrao=true;
                        spendcard(i,j);
                        break;
                    }
                if(!hasganrao)
                {
                    int tmp_should=8+wantlv/2;
                    cout<<name[i]<<"没有干扰，分数-"<<tmp_should<<"\n";
                    score[i]-=tmp_should;
                    cout<<name[i]<<"目前分数"<<score[i]<<"/150\n";
                    maydied(i);
                }
            }
            spendcard(I,wantt);
        }
        if(wantk==5)
        {
            for(int i=1; i<=n; i++)
            {
                if(!alive[i] || i==I)
                    continue;
                bool hasneijuan=false;
                if(role[i]==3)
                {
                    cout<<"触发徐慕熹技能[数学大佬]，无视本次考试\n";
                    break;
                }
                for(int j=1; j<=cn[i]; j++)
                    if(hold[i][j]==1)
                    {
                        cout<<name[i]<<"使用了内卷\n";
                        hasneijuan=true;
                        spendcard(i,j);
                        break;
                    }
                if(!hasneijuan)
                {
                    int tmp_should=8+wantlv/2;
                    cout<<name[i]<<"没有内卷，分数-"<<tmp_should<<"\n";
                    score[i]-=tmp_should;
                    cout<<name[i]<<"目前分数"<<score[i]<<"/150\n";
                    maydied(i);
                }
            }
            spendcard(I,wantt);
        }
        if(wantk==6)
        {
            if(neijuanjl)
                cout<<name[neijuanjl]<<"已经使用了内卷禁令！\n";
            else
            {
                cout<<"所有人禁止出内卷一回合\n";
                neijuanjl=I;
                spendcard(I,wantt);
            }
        }
        if(wantk==7)
        {
            int maxscore=-114514;
            for(int i=1; i<=n; i++)
                if(alive[i])
                    maxscore=max(maxscore,score[i]);
            for(int i=1; i<=n; i++)
                if(alive[i] && score[i]==maxscore)
                {
                    int tmp_should=8+wantlv/2;
                    cout<<name[i]<<"被制裁了，分数-"<<tmp_should<<"\n";
                    score[i]-=tmp_should;
                    cout<<name[i]<<"目前分数"<<score[i]<<"/150\n";
                    maydied(i);
                }
            spendcard(I,wantt);
        }
        if(wantk==8)
        {
            int minscore=114514;
            for(int i=1; i<=n; i++)
                if(alive[i])
                    minscore=min(minscore,score[i]);
            for(int i=1; i<=n; i++)
                if(alive[i] && score[i]==minscore)
                {
                    int tmp_should=8+wantlv/4;
                    cout<<name[i]<<"被奖励了，分数+"<<tmp_should<<"\n";
                    score[i]+=tmp_should;
                    if(score[i]>150)
                        score[i]=150;
                    cout<<name[i]<<"目前分数"<<score[i]<<"/150\n";
                }
            spendcard(I,wantt);
        }
        if(wantk==9)
            cout<<"幸运草不是主动卡牌！\n";
        if(fsuc)
            fcnt=0;
        else
            fcnt++;
        if(isAI[I])
            Sleep(1000);
        if(leftn==1)
            break;
        gpause(I);
        goto startout;
    }
    int winner=0;
    for(int i=1; i<=n; i++)
    {
        if(alive[i])
            winner=i;
    }
    cout<<"胜利者是：";
    if(winner==0)
        cout<<"空气！\n";
    else
        cout<<name[winner]<<"\n";
    getchar();
    return 0;
}
