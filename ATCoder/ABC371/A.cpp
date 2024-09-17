#include <bits/stdc++.h>

#define i64 long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define fdn(i,r,l) for(int i=(r);i>=(l);i--)
#define pii pair<int,int>
using namespace std;

typedef long long ll;
typedef double db;
typedef __int128 i128;

int a1,a2,a3;
char ab,ac,bc;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>ab>>ac>>bc;
    if(ab=='<'&&ac=='<'&&bc=='<') // a<b<c
        cout<<'B';
    if(ab=='>'&&ac=='>'&&bc=='>') // c<b<a
        cout<<'B';
    if(ab=='>'&&ac=='<'&&bc=='<') // b<a<c
        cout<<'A';
    if(ac=='>'&&ab=='<'&&bc=='>') // c<a<b
        cout<<'A';
    if(ac=='<'&&ab=='<'&&bc=='>') // a<c<b  
        cout<<'C';
    if(ac=='>'&&ab=='>'&&bc=='<') // b<c<a
        cout<<'C';
}