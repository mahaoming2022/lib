#include <bits/stdc++.h>
using namespace std;
#define int long long
int l[200010], r[200010], ll = 1e18, rr = -1e18;
int x[200010];
signed main() {
	ios::sync_with_stdio(false);
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> l[i] >> r[i];
		ll = min(ll, l[i]);
		rr = max(rr, r[i]);
	}
	if (rr < 0 || ll > 0) {
		cout << "No";
		return 0;
	}
	int sum = 0;
	for (int i = 1; i <= n; i++)
		x[i] = l[i], sum += l[i];
	for (int i = 1; i <= n; i++) {
		if (sum < 0) {
			x[i] += min(r[i] - l[i], -sum);
			sum = sum - l[i] + x[i];
		}
	}
	if (sum == 0) {
		cout << "Yes\n";
		for (int i = 1; i <= n; i++)
			cout << x[i] << ' ';
	} else
		cout << "No";
	return 0;
}