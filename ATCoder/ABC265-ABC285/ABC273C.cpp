#include<bits/stdc++.h>

using namespace std;

int main()
{
  int n, a;
  map<int, int> mp;
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a, mp[a]++;
  for(auto it = mp.rbegin(); it != mp.rend(); it++) cout << it->second << "\n";
  for(int i = 1; i <= n - (int)mp.size(); i++) cout << 0 << "\n";
  return 0;
}
