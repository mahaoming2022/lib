#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;

void welcome()
{
    system("cls");
    cout<<"��ӭ����712����ɱ��1.3����\n";
    cout<<"��У�xxmzhuyuyang & MasonXu     ���룺MasonXu\n";
    cout<<"A-���ƽ���	B-��ʼ��Ϸ\n";
    char key=getch();
    if(key=='a')
    {
        cout<<"���θ������ݣ����Ƶȼ������˲ݣ���ɫ��Ľ��\n";
        cout<<"1. ���ƽ��� (��42��)\n";
        cout<<"(1) �ھ�*8 ʹ�Լ��ɼ�+8\n";
        cout<<"(2) ����*8 ����'����'Ч��\n";
        cout<<"(3) ����*10 ʹ������ҳɼ�-8\n";
        cout<<"(4) ��д*4 ���Լ����������Ҫô��1��'����'��Ҫô�ɼ�-8\n";
        cout<<"(5) ����*4 ���Լ����������Ҫô��1��'�ھ�'��Ҫô�ɼ�-8\n";
        cout<<"(6) �ھ����*2 ������Ҳ���������'�ھ�'������1�غ�\n";
        cout<<"(7) �Ʋþ��*2 ʹ�ɼ�����߳ɼ�-8\n";
        cout<<"(8) ��������*2 ʹ�ɼ�����߳ɼ�+8\n";
        cout<<"(9) ���˲�*2 �и��ʳ鵽�߼�����\n";
        cout<<"2. ��������\n";
        cout<<"ÿ�˳�ʼ150�֣�����150�֣�����С��90�ֱ���̭\n";
        cout<<"ÿ�˳�ʼ4������ƣ��������������ƣ�ÿ���ڻغϿ�ʼ��2����\n";
        cout<<"ÿ�����Լ��غϿ��Գ������ĸ��ţ���ֻ�ܳ�һ���ھ�\n";
        cout<<"�һغϽ���ʱֻ�ܱ���3����\n";
        cout<<"3.��ɫ\n";
        cout<<"(1) ��ŵ\n";
        cout<<"�������������ھ��Ѿ�������������Լ�ʹ���ھ�����ټ�4��\n";
        cout<<"(2) ������\n";
        cout<<"������ʹ�ø���ʱ�����Ŷ����������-4\n";
        cout<<"(3) ��Ľ��\n";
        cout<<"����RP��û�����˲�ʱ��Ϊ��C�����˲ݣ������˲�ʱ���˲ݵȼ���Ϊ+1\n";
        cout<<"��ѧ���У����ӿ���\n";
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

string rolename[1005]= {"","��ŵ","������","��Ľ��"};
int zazz[1005]= {0,8,8,10,4,4,2,2,2,4};
int lvchance[1005]= {0,100,40,30,20,10,3,2,1,0,0};
bool fsuc;
void maydied(int x)
{
    if(score[x]<90)
    {
        cout<<name[x]<<"��������90����xb�����ˣ�\n";
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
    cout<<"������ "<<name[x]<<" ����\n";
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
    string tmp1[14]= {"","�ھ�","����","����","��д","����","�ھ����","�Ʋþ��","��������","���˲�"};
    cout<<tmp1[x];
    string tmp2[14]= {"","C","Un","R","E","L","M","Ul","S"};
    if(y>1)
        cout<<"["<<tmp2[y]<<"]";
}
int main()
{
    srand((unsigned)time(NULL));
    welcome();
    cout<<"������������\n";
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cout<<"���������"<<i<<"������\n";
        cin>>name[i];
        score[i]=150;
        randcard(i,2);
        alive[i]=true;
        cout<<name[i]<<"�Ƿ�ʹ��AI�й�?(Y/N)\n";
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
        cout<<"��ǰ�� "<<name[I]<<" �Ļغ�";
        if(isAI[I])
            cout<<"����������ڱ�AI�йܣ�";
        cout<<"\n��ң�\n";
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
            cout<<name[neijuanjl]<<"����ʹ���ھ����\n";
        cout<<"���ƣ�\n";
        cout<<cn[I]<<endl;
        for(int i=1; i<=cn[I]; i++)
        {
            int t=hold[I][i];
            nameof(t,holdlv[I][i]);
            cout<<"("<<(char)('A'+i-1)<<")\t";
        }
        cout<<"\n";
        cout<<"��ѡ��Ҫ�����ƣ������غϰ�0����\n";
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
                cout<<"������"<<cn[I]-3<<"����\n";
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
                cout<<"��������";
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
        cout<<"��ʹ��";
        nameof(wantk,holdlv[I][wantt]);
        cout<<"\n";
        if(wantk==1)
        {
            if(neijuanjl && neijuanjl!=I)
                cout<<name[neijuanjl]<<"����ʹ���ھ���\n";
            else if(juaned)
                cout<<"���ڱ��غ��Ѿ�����ˣ�\n";
            else
            {
                int tmp_should=7+wantlv;
                if(role[I]==1)
                {
                    cout<<"������ŵ����[��������]���ɼ�����+4\n";
                    tmp_should+=4;
                }
                cout<<"�ɼ�+"<<tmp_should<<"\n";
                score[I]+=tmp_should;
                if(score[I]>150)
                    score[I]=150;
                cout<<"Ŀǰ����"<<score[I]<<"/150\n";
                juaned=true;
                spendcard(I,wantt);
            }
        }
        if(wantk==2)
            cout<<"��������ʹ�ð��ã�\n";
        if(wantk==3)
        {
            cout<<"��ѡ����Ŷ���\n";
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
                        cout<<name[ganrao]<<"����һ�Ű��ã������˸��ŵ�Ч��\n";
                        hasbailan=true;
                        bailanlv=holdlv[ganrao][i];
                        spendcard(ganrao,i);
                        break;
                    }
                }
                if(hasbailan && bailanlv>1)
                {
                    cout<<ganrao<<"ʹ����";
                    nameof(2,bailanlv);
                    cout<<"����������Ч��\n";
                    int tmp_should=(bailanlv+1)/3;
                    cout<<"��ĳɼ�-"<<tmp_should<<"\n";
                    score[I]-=tmp_should;
                    maydied(I);
                }
                if(!hasbailan)
                {
                    int tmp_should=7+wantlv;
                    if(role[I]==2)
                    {
                        cout<<name[ganrao]<<"û�а��ã�������������[����]���۷ֶ���+4\n";
                        tmp_should+=4;
                    }
                    cout<<name[ganrao]<<"�ɼ�-"<<tmp_should<<"\n";
                    score[ganrao]-=tmp_should;
                    cout<<name[ganrao]<<"Ŀǰ����"<<score[ganrao]<<"/150\n";
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
                        cout<<name[i]<<"ʹ���˸���\n";
                        hasganrao=true;
                        spendcard(i,j);
                        break;
                    }
                if(!hasganrao)
                {
                    int tmp_should=8+wantlv/2;
                    cout<<name[i]<<"û�и��ţ�����-"<<tmp_should<<"\n";
                    score[i]-=tmp_should;
                    cout<<name[i]<<"Ŀǰ����"<<score[i]<<"/150\n";
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
                    cout<<"������Ľ�似��[��ѧ����]�����ӱ��ο���\n";
                    break;
                }
                for(int j=1; j<=cn[i]; j++)
                    if(hold[i][j]==1)
                    {
                        cout<<name[i]<<"ʹ�����ھ�\n";
                        hasneijuan=true;
                        spendcard(i,j);
                        break;
                    }
                if(!hasneijuan)
                {
                    int tmp_should=8+wantlv/2;
                    cout<<name[i]<<"û���ھ�����-"<<tmp_should<<"\n";
                    score[i]-=tmp_should;
                    cout<<name[i]<<"Ŀǰ����"<<score[i]<<"/150\n";
                    maydied(i);
                }
            }
            spendcard(I,wantt);
        }
        if(wantk==6)
        {
            if(neijuanjl)
                cout<<name[neijuanjl]<<"�Ѿ�ʹ�����ھ���\n";
            else
            {
                cout<<"�����˽�ֹ���ھ�һ�غ�\n";
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
                    cout<<name[i]<<"���Ʋ��ˣ�����-"<<tmp_should<<"\n";
                    score[i]-=tmp_should;
                    cout<<name[i]<<"Ŀǰ����"<<score[i]<<"/150\n";
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
                    cout<<name[i]<<"�������ˣ�����+"<<tmp_should<<"\n";
                    score[i]+=tmp_should;
                    if(score[i]>150)
                        score[i]=150;
                    cout<<name[i]<<"Ŀǰ����"<<score[i]<<"/150\n";
                }
            spendcard(I,wantt);
        }
        if(wantk==9)
            cout<<"���˲ݲ����������ƣ�\n";
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
    cout<<"ʤ�����ǣ�";
    if(winner==0)
        cout<<"������\n";
    else
        cout<<name[winner]<<"\n";
    while(1) cin>>winner;
    return 0;
}
