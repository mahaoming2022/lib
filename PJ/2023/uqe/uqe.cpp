#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)

using namespace std;

int T,M;

inline void printQ(int a,int b)
{
    if(a==0) return ;
    if(a%b==0){cout<<a/b;return ;}
    int f=0;
    if(a*b<0) f=1,a=abs(a),b=abs(b);
    if(f) cout<<'-';
    int g=__gcd(a,b);
    cout<<a/g<<'/'<<b/g;
}

int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>T>>M;
    while(T--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(a<0){a=-a,b=-b,c=-c;}
        int delta=b*b-4*a*c;
        if(delta<0){cout<<"NO"<<endl;continue;}
        if(delta==0)
        {
            // belong to Q
            // -b/2a
            if(-b==0){cout<<0<<endl;continue;}
            printQ(-b,2*a);
            cout<<endl;
            continue;
        }
        // -b/2a+sqrt(delta)/2a
        // Q+p*sqrt(delta/(p*p))/2a
        int p=1,q=2*a;
        rep(i,2,sqrt(delta)+1)
            while(delta%(i*i)==0)
                p*=i,delta/=i*i;
        if(delta==1)
        {
            // belong to Q
            // -b/2a+p/2a
            int ax=-b+p,bx=2*a;
            int g=__gcd(ax,bx);
            printQ(ax,bx);
            if(ax==0) cout<<0;
        }
        else
        {
            // belong to R
            printQ(-b,2*a);
            if(-b!=0) cout<<'+';
            int g=__gcd(p,q);
            p/=g,q/=g;
            if(p!=1)
                cout<<p<<"*sqrt("<<delta<<')';
            else if(p==1)
                cout<<"sqrt("<<delta<<')';
            if(q!=1)
                cout<<"/"<<q;
        }
        cout<<endl;
    }
}

// 这题唯一的坑点是会把 43 行没根号枚举的卡掉。