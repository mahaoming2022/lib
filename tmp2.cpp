#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> A(N), B(N);
	for (int i = 0; i < N; i++)
		cin >> A[i] >> B[i];
	vector<vector<int>> inv(M + 1);
	for (int i = 0; i < N; i++)
	{
		inv[A[i]].push_back(i);
		inv[B[i]].push_back(i);
	}
	vector<int> cnt(N), ans(M + 3);
	int cnt_zero = N;
	for (int i = 1, j = 1; i <= M;)
	{
		while (j <= M and cnt_zero != 0)
		{
			for (auto &x : inv[j])
			{
				if (cnt[x] == 0)
					cnt_zero--;
				cnt[x]++;
			}
			j++;
		}
		if (cnt_zero != 0)
			break;
		ans[j - i]++, ans[M + 1 - i + 1]--;
		for (auto &x : inv[i])
		{
			cnt[x]--;
			if (cnt[x] == 0)
				cnt_zero++;
		}
		i++;
	}
	for (int i = 1; i <= M; i++)
	{
		ans[i] += ans[i - 1];
		cout << ans[i] << " \n"[i == M];
	}
}
