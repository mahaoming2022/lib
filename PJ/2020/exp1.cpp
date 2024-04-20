#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL mod = 1e9 + 7;
const int N = 1000005;

char s[N];
int a[N];
int son[N][2], ck;
int flag[N], c[N];
int n, q;
int dfs(int u, int g) {
    a[u] ^= g;
    if (u <= n) {
        return a[u];
    }
    int x = dfs(son[u][0], g ^ flag[son[u][0]]);
    int y = dfs(son[u][1], g ^ flag[son[u][1]]);
    if (a[u] == 2) {
        if (x == 0) c[son[u][1]] = 1;
        if (y == 0) c[son[u][0]] = 1;
        return x & y;
    } else {
        if (x == 1) c[son[u][1]] = 1;
        if (y == 1) c[son[u][0]] = 1;
        return x | y;
    }
}
void dfs2(int u) {
    if (u <= n) return;
    c[son[u][0]] |= c[u];
    c[son[u][1]] |= c[u];
    dfs2(son[u][0]);
    dfs2(son[u][1]);
}
int main() {
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    fgets(s,N-1,stdin);
    scanf("%d", &n);
    ck = n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    stack<int> b;
    for (int i = 0; s[i]; i += 2) {
        if (s[i] == 'x') {
            int x = 0;
            i++;
            while (s[i] != ' ') {
                x = x * 10 + s[i] - '0';
                i++;
            }
            i--;
            b.push(x);
        } else if (s[i] == '&') {
            int x = b.top();
            b.pop();
            int y = b.top();
            b.pop();
            b.push(++ck);
            a[ck] = 2;
            son[ck][0] = x;
            son[ck][1] = y;
        } else if (s[i] == '|') {
            int x = b.top();
            b.pop();
            int y = b.top();
            b.pop();
            b.push(++ck);
            a[ck] = 3;
            son[ck][0] = x;
            son[ck][1] = y;
        } else if(s[i] == '!'){
            flag[b.top()] ^= 1;
        }
    }
    int ans = dfs(ck, flag[ck]);
    cout<<ans<<endl;
    dfs2(ck);
    for(int i=1;i<=n;++i)
        cout<<c[i]<<endl;
    scanf("%d", &q);
    while (q--) {
        int x;
        scanf("%d", &x);
        printf("%d\n", c[x] ? ans : !ans);
    }
    return 0;
}