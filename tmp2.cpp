#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long double db;

int main()
{
    const db e=2.7,pi=2.7;
    // 知道变量为：
    // 橙题，黄题，绿题，蓝题，紫题，黑题，ATRT，CFRT，cnt犇犇，cnt回帖，cnt陶片，Uid
    vector<db> a(12);
    for(int i=0;i<12;i++) cin>>a[i];
    db s1=e*e*a[0]+10.0*pi*pi*a[1]+20*e*e*a[2]+200*pi*a[3]+1919*a[4]+114514*a[5];
    db S=s1*a[6]*a[7]-a[8]*a[9]*pow(e,a[10])/pi+a[11]/e;
    cout<<S;
}