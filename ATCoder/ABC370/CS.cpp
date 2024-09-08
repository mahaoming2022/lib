#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int H, W, Q;
  cin >> H >> W >> Q;

  vector<set<int>> g1(H), g2(W);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      g1[i].insert(j);
      g2[j].insert(i);
    }
  }

  auto erase = [&](int i, int j) { g1[i].erase(j), g2[j].erase(i); };

  while (Q--) {
    int R, C;
    cin >> R >> C;
    --R, --C;

    if (g1[R].count(C)) {
      erase(R, C);
      continue;
    }

    // up
    {
      auto it = g2[C].lower_bound(R);
      if (it != begin(g2[C])) erase(*prev(it), C);
    }
    // down
    {
      auto it = g2[C].lower_bound(R);
      if (it != end(g2[C])) erase(*it, C);
    }
    // left
    {
      auto it = g1[R].lower_bound(C);
      if (it != begin(g1[R])) erase(R, *prev(it));
    }
    // right
    {
      auto it = g1[R].lower_bound(C);
      if (it != end(g1[R])) erase(R, *it);
    }
  }

  int ans = 0;
  for (int i = 0; i < H; i++) ans += g1[i].size();
  cout << ans << "\n";
}
