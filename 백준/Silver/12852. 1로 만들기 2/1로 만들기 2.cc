#include<bits/stdc++.h>

using namespace std;
int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> dp(n + 1), path(n + 1);
	for (int i = 1; i <= n; i++)
	{
		if (i == 1) dp[i] = 0;
		else
		{
			dp[i] = dp[i - 1] + 1;
			path[i] = i - 1;
			if (i % 3 == 0 && dp[i] > dp[i / 3] + 1)
			{
				dp[i] = dp[i / 3] + 1;
				path[i] = i / 3;
			}
			if (i % 2 == 0 && dp[i] > dp[i / 2] + 1)
			{
				dp[i] = dp[i / 2] + 1;
				path[i] = i / 2;
			}
		}
	}
	cout << dp[n] << "\n";

	while (n)
	{
		cout << n << " ";
		n = path[n];
	}
	return 0;
}