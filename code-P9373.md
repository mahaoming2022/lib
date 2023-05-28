第二份代码如下：

```cpp
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#ifdef CSPAKDUCK
    #define IOIAKME 0
#endif
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define spe putchar(' ')
#define edl putchar('\n')
#define space ' '
#define int long long
using db = double;
using ll = long long;
using ull = unsigned long long;
const int INF = 1 << 30;
const long long INFL = 1LL << 60;
const db pi = 3.14159;
namespace io
{
    template <class AC>
    void read(AC &x){x = 0;int f = 0;char ch = getchar();while (ch < '0' || ch > '9'){f |= (ch == '-');ch = getchar();}while (ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + (ch ^ 48);ch = getchar();}x = f ? -x : x;}
    template <class AC>
    inline void write(AC x)
    {if (x < 0){putchar('-');x = -x;}if (x > 9)write(x / 10);putchar(x % 10 + '0');}
    inline int readint(){int x = 0;int f = 0;char ch = getchar();while (ch < '0' || ch > '9'){f |= (ch == '-');ch = getchar();}while (ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + (ch ^ 48);ch = getchar();}x = f ? -x : x;}
};

using namespace io;

signed main()
{
    int t;
    read(t);
    while(t--){
        int n=readint(),k=readint();
        if(2*k>=n){
            cout<<"-1"<<endl;
            continue;
        }
        else 
            cout<<k<<" "<<n-k<<endl;
    }
    return 0;
}
```

最终的代码:

```cpp
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#ifdef CSPAKDUCK
    #define IOIAKME 0
#endif
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define spe putchar(' ')
#define edl putchar('\n')
#define space ' '
#define int long long
using db = double;
using ll = long long;
using ull = unsigned long long;
const int INF = 1 << 30;
const long long INFL = 1LL << 60;
const db pi = 3.14159;
namespace io
{
    template <class AC>
    void read(AC &x){x = 0;int f = 0;char ch = getchar();while (ch < '0' || ch > '9'){f |= (ch == '-');ch = getchar();}while (ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + (ch ^ 48);ch = getchar();}x = f ? -x : x;}
    template <class AC>
    inline void write(AC x)
    {if (x < 0){putchar('-');x = -x;}if (x > 9)write(x / 10);putchar(x % 10 + '0');}
    inline int readint(){int x = 0;int f = 0;char ch = getchar();while (ch < '0' || ch > '9'){f |= (ch == '-');ch = getchar();}while (ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + (ch ^ 48);ch = getchar();}x = f ? -x : x;}
};

using namespace io;

signed main()
{
    int t;
    read(t);
    while(t--){
        int n=readint(),k=readint();
        if(k>=n-k){
            cout<<"-1"<<endl;
            continue;
        }
        else 
            cout<<k<<" "<<n-k<<endl;
    }
    return 0;
}
```

珍爱生命，远离抄袭！
