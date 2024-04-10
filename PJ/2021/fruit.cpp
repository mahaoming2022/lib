#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
const int N=2e5+23;

struct Fruit{
    bool k;
    int pre,nxt;
}f[N];

struct Group{
    int st,ed;
    bool k;
    Group* pre;
    Group* nxt;
}tmp[N];

Group *head=nullptr,*tail=nullptr;

int n;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    cin>>n;
    f[0].nxt=1;
    rep(i,1,n)
    {
        cin>>f[i].k;
        f[i].pre=i-1;
        f[i].nxt=i+1;
    }
    f[n].nxt=0;
    int bg=1,len=1;
    rep(i,2,n)
    {
        if(f[i-1].k!=f[i].k)
        {
            Group& x=tmp[i];
            x.st=bg,x.ed=bg+len-1;
            x.k=f[i-1].k;
            if(head==nullptr)
            {
                head=&x;
                tail=&x;
            }
            else{
                x.pre=tail;
                tail->nxt=&x;
                tail=&x;
                tail->nxt=nullptr;
            }
            bg=i;
            len=1;
        }
        else
            len++;
    }
    Group x;
    x.st=bg,x.ed=bg+len-1;
    x.k=f[n].k;
    if(head==nullptr)
    {
        head=&x;
        tail=&x;
    }
    else{
        x.pre=tail;
        tail->nxt=&x;
        tail=&x;
    }
    tail->nxt=nullptr;
    while(head!=nullptr)
    {
        for(Group* i=head;i!=nullptr;i=i->nxt)
        {
            //delete the first fruit
            cout<<(i->st)<<' ';
            f[f[i->st].pre].nxt=f[i->st].nxt;
            f[f[i->st].nxt].pre=f[i->st].pre;
            i->st=f[i->st].nxt;
            if(i->st==0)
            {
                if(i!=head){
                    tail=i->pre;
                    tail->nxt=nullptr;
                }
                else{
                    head=nullptr;
                    tail=nullptr;
                    return 0;
                }
            }
            if((i->st)>(i->ed))
            {
                if(i==head)
                {
                    head=i->nxt;
                    head->pre=nullptr;
                }
                else{
                    i->pre->nxt=i->nxt;
                    i->nxt->pre=i->pre;
                }
                continue;
            }
            //merge the group
            if(i!=head&&(i->k)==((i->pre)->k))
            {
                i->pre->ed=i->ed;
                if(i!=tail){
                    i->pre->nxt=i->nxt;
                    i->nxt->pre=i->pre;
                }
                else{
                    tail=i->pre;
                    tail->nxt=nullptr;
                }
            }
        }
        cout<<endl;
    }
}