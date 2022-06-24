#include<bits/stdc++.h>

using namespace std;
int n, m, k;
typedef long long ll;
ll dp[31][31][1 << 9];
ll cmb[30][30];
const ll MOD = 1000000007LL;

ll f(int now, int road, int flag)
{
	if (road == 0) return flag == 0;
	if (now == n) return 0;
	ll& ret = dp[now][road][flag];
	if (ret != -1) return ret;
	ret = 0;

	int newk = min(n - now, k);
	for (int i = 0; i < 1 << newk; i++)
	{
		int cnt = 0;
		for (int j = i; j; j &= (j - 1))++cnt;
		if (((cnt ^ flag) & 1) || road < cnt) continue;

		int now_flag = i ^ (flag >> 1);

		for (int p = 0; road - cnt - p * 2 >= 0; p++)
		{
			ll nowcnt = cmb[p + newk - 1][newk - 1];
			ll nowans = (f(now + 1, road - cnt - p * 2, now_flag) * nowcnt) % MOD;
			ret = (ret + nowans) % MOD;
		}
	}
	return ret;

}
int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	for (int i = 0; i <= 50; i++)
	{
		for (int j = 0; j <= 50; j++)
		{
			if (j == 0 || i == j) cmb[i][j] = 1;
			else cmb[i][j] = (cmb[i - 1][j] + cmb[i - 1][j - 1]) % MOD;
		}
	}
	cin >> n >> m >> k;
	memset(dp, -1, sizeof(dp));
	cout << f(1, m, 0);
	return 0;
}