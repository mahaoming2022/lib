#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)

using namespace std;
typedef long long ll;

const int N=114;

ll latest_pos=0;

struct node
{
    string name;
    vector<pair<int,string> > mem;
    ll fi,o_size;
    void calc_fill()
    {
        for(auto i:mem)
            this->fi=max(this->fi,ac[i.first].fi);
    }
    bool check_basic()
    {
        return (name=="byte"||name=="int"||name=="short"||name=="long");
    }
};

struct ele
{
    int ty;
    string name;
    ll start_pos,end_pos;
};

int cnt1=0,cnt2=0;
node ac[N];
ele ad[N];
map<string,int> name_stu;
map<string,int> name_ele;

void calc_size(int j)
{
    if(ac[j].name=="byte"){ac[j].o_size=0;return ;}
    if(ac[j].name=="short"){ac[j].o_size=1;return ;}
    if(ac[j].name=="int"){ac[j].o_size=3;return ;}
    if(ac[j].name=="long"){ac[j].o_size=7;return ;} 
    ll lp=0;
    for(auto i:ac[j].mem)
    {
        lp=ac[i.first].fi*(ll)ceil(lp/ac[i.first].fi);
        lp+=ac[i.first].o_size;
    }
    ac[j].o_size=lp;
}

void calc_start_pos(int j)
{
    ll fi1=ac[ad[j].ty].fi;
    ad[j].start_pos=fi1*(ll)ceil(latest_pos/fi1);
    latest_pos=ad[j].start_pos;
} 
void calc_end_pos(int j)
{
    for(auto i:ac[ad[j].ty].mem)
    {
        ll fi2=ac[i.first].fi;
        latest_pos=fi2*(ll)ceil(latest_pos/fi2);
        latest_pos+=ac[i.first].o_size;
    }
    ad[j].end_pos=latest_pos;
}


void new_stu()
{
    ++cnt1;
    node ns;int k;
    cin>>ns.name>>k;
    rep(i,1,k)
    {
        string ty,na;
        cin>>ty>>na;
        ac[cnt1].mem.push_back({name_stu[ty],na});
    }
    name_stu[ns.name]=cnt1;
    // ac[cnt1].calc_fill();
    // ac[cnt1].calc_size();
}

void new_ele()
{
    ++cnt2;
    ele ne;string ty1;
    cin>>ty1>>ne.name;
    ne.ty=name_stu[ty1];
    // name_ele[ne.name]=cnt2;
    name_ele[ne.name]=cnt2;
    ad[cnt2]=ne;
    calc_start_pos(cnt2);
    calc_end_pos(cnt2);
}


void find_ele()
{
    string ele_name;
    
}

void find_addr()
{
    
}

int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int Q;
    cin>>Q;
    while(Q--)
    {
        int o;
        cin>>o;
        if(o==1) new_stu();
        if(o==2) new_ele();
        if(o==3) find_ele();
        if(o==4) find_addr();
    }
}