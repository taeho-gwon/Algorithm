#include<bits/stdc++.h>
#define N 100000
#define M 100
#define C_MAX 1000
using namespace std;
int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	int m, k;
	cin >> m >> k;
	vector<int> dol(k), grundy(N * 2 + 1);
	for (int i = 0; i < k; i++) cin >> dol[i];
	for (int i = 1; i <= N*2; i++)
	{
		vector<int> chk(M);
		for (int j = 0; j < k && dol[j] <= i; j++)
			chk[grundy[i - dol[j]]] = 1;
		while (chk[grundy[i]] == 1) grundy[i]++;
	}
	if (m <= N)
	{
		int ans = 0;
		for (int i = 1; i <= m; i++) ans += (grundy[i] == 0);
		cout << ans;
		return 0;
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) ans += (grundy[i] == 0);
	int cycle_len = 1;
	for (int i = 2; i <= C_MAX; i++)
	{
		bool chk = true;
		for (int j = 1; j <= C_MAX; j++)
		{
			if (grundy[N + j] != grundy[N + i + j])
			{
				chk = false;
				break;
			}
		}
		if (chk)
			cycle_len = i;
	}

	int zero = 0;
	for (int i = 1; i <= cycle_len; i++)
	{
		if (grundy[i + N] == 0) zero++;
	}
	ans += (m - N) / cycle_len * zero;
	for (int i = 1; i <= (m - N) % cycle_len; i++)
	{
		ans += (grundy[N + i] == 0);
	}
	cout << ans;
	return 0;
}