#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); i++)

using namespace std;
typedef long long ll;
typedef double db;

const int N = 114;

int n;
ll sum[N][N][N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    cin >> n;
    rep(i, 1, n) rep(j, 1, n) rep(k, 1, n)
    {
        cin >> sum[i][j][k];
        sum[i][j][k] += sum[i - 1][j][k] + sum[i][j - 1][k] + sum[i][j][k - 1] - sum[i - 1][j - 1][k] - sum[i - 1][j][k - 1] - sum[i][j - 1][k - 1] + sum[i - 1][j - 1][k - 1];
    }
    int Q;
    cin >> Q;
    while (Q--)
    {
        int i, j, k, i2, j2, k2;
        cin >> i >> i2 >> j >> j2 >> k >> k2;
        ll ans = sum[i2][j2][k2] - sum[i - 1][j2][k2] - sum[i2][j - 1][k2] - sum[i2][j2][k - 1] + sum[i - 1][j - 1][k2] + sum[i - 1][j2][k - 1] + sum[i2][j - 1][k - 1] - sum[i - 1][j - 1][k - 1];
        cout << ans << endl;
    }
}