#include<bits/stdc++.h>
#define MOD 1000000
using namespace std;
int dp[100][100];
int f(int x, int y)
{
	int& ret = dp[x][y];
	if (ret != -1) return ret;
	if (x == 0) return ret = (y==0);
	ret = 0;
	for (int i = 0; i < x; i++)
		ret = (ret + f(y + i, x - i - 1)) % MOD;
	
	return ret;
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	int n, ans=0;
	cin >> n;
	memset(dp, -1, sizeof(dp));
	if (n == 1)
	{
		cout << 1;
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		ans = (ans + f(n - 1 - i, i))%MOD;
		ans = (ans + f(i, n - 1 - i))%MOD;
	}

	cout << ans;
	return 0;
}